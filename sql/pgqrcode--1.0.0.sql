CREATE OR REPLACE FUNCTION generate_qr_code_svg(input TEXT, scale FLOAT8)
RETURNS TEXT
AS 'MODULE_PATHNAME', 'generate_qr_code_svg'
LANGUAGE C STRICT;
