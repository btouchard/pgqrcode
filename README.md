# pgqrcode

pgqrcode is a PostgreSQL extension that allows you to generate QR codes in SVG format directly from your database.

## Features

- Generate QR codes in SVG format
- Simple integration with PostgreSQL
- Based on Nayuki's [QR Code generator](https://github.com/nayuki/QR-Code-generator) library

## Prerequisites

- PostgreSQL 9.5 or higher
- PostgreSQL development tools (postgresql-server-dev-all on Debian/Ubuntu systems)
- C compiler (gcc or clang)
- Make

## Installation

1. Clone this repository:
   ```
   git clone https://github.com/btouchard/pgqrcode.git
   cd pgqrcode
   ```

2. Compile the extension:
   ```
   make
   ```

3. Install the extension:
   ```
   sudo make install
   ```

4. Connect to your PostgreSQL database:
   ```
   psql -d your_database
   ```

5. Create the extension:
   ```sql
   CREATE EXTENSION pgqrcode;
   ```

## Usage

Once the extension is installed, you can generate QR codes using the `generate_qr_code_svg` function:

```sql
SELECT generate_qr_code_svg('https://www.kolapsis.com');
```

This function returns an SVG string representing the QR code for the provided text.

## Examples

1. Generate a QR code for a URL:
   ```sql
   SELECT generate_qr_code_svg('https://www.kolapsis.com');
   ```

2. Save the QR code in a table:
   ```sql
   CREATE TABLE qr_codes (id SERIAL PRIMARY KEY, content TEXT, svg TEXT);
   INSERT INTO qr_codes (content, svg) VALUES ('Hello, World!', generate_qr_code_svg('Hello, World!'));
   ```

3. Retrieve and use the QR code:
   ```sql
   SELECT svg FROM qr_codes WHERE content = 'Hello, World!';
   ```

## Limitations

- The maximum content size depends on QR code capacity (version 40, low error correction level).
- The extension only generates QR codes in SVG format. Other formats are not supported.

## Troubleshooting

If you encounter issues during installation or use of the extension, ensure that:

1. PostgreSQL is properly installed and configured.
2. PostgreSQL development tools are installed.
3. You have the necessary permissions to install the extension.

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE.md](LICENSE) file for details.

## Acknowledgements

- [Nayuki](https://github.com/nayuki) for the QR Code generator library.
- The PostgreSQL community for their excellent resources on extension development.