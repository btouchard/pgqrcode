CREATE FUNCTION generate_qr_code_svg(text, integer DEFAULT 1) RETURNS text
AS 'MODULE_PATHNAME', 'generate_qr_code_svg'
LANGUAGE C STRICT;

COMMENT ON FUNCTION generate_qr_code_svg(text, integer) IS 'Generate QR code as SVG. The second parameter is the scale factor (default 1).';