#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include "qrcodegen.h"
#include "lib/stringinfo.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(generate_qr_code_svg);

Datum
generate_qr_code_svg(PG_FUNCTION_ARGS)
{
    text *input_text;
    char *input_str;
    int scale = 1;
    enum qrcodegen_Ecc errCorLvl;
    uint8_t qr[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    bool success;
    int size;
    StringInfoData buf;
    text *result;
    int x, y;

    input_text = PG_GETARG_TEXT_PP(0);
    input_str = text_to_cstring(input_text);

    if (PG_NARGS() > 1) {
        scale = PG_GETARG_INT32(1);
        if (scale < 1) {
            scale = 1;
        }
    }

    errCorLvl = qrcodegen_Ecc_LOW;

    success = qrcodegen_encodeText(input_str, tempBuffer, qr, errCorLvl,
        qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
    
    if (!success) {
        ereport(ERROR,
                (errcode(ERRCODE_INTERNAL_ERROR),
                 errmsg("Failed to generate QR code")));
    }
    
    size = qrcodegen_getSize(qr);
    initStringInfo(&buf);
    
    appendStringInfo(&buf, "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 %d %d\" width=\"%d\" height=\"%d\" stroke=\"none\">",
                     size, size, size * scale, size * scale);
    appendStringInfo(&buf, "<rect width=\"100%%\" height=\"100%%\" fill=\"#FFFFFF\"/>");
    appendStringInfo(&buf, "<path d=\"");
    
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (qrcodegen_getModule(qr, x, y)) {
                appendStringInfo(&buf, "M%d,%dh1v1h-1z ", x, y);
            }
        }
    }
    
    appendStringInfo(&buf, "\" fill=\"#000000\"/>");
    appendStringInfo(&buf, "</svg>");
    
    result = cstring_to_text(buf.data);
    pfree(buf.data);
    pfree(input_str);
    
    PG_RETURN_TEXT_P(result);
}