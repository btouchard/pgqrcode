CREATE FUNCTION generate_qr_code_svg(text) RETURNS text
AS 'MODULE_PATHNAME', 'generate_qr_code_svg'
LANGUAGE C STRICT;