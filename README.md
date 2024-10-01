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
-- Generate a QR code with default scale (1)
SELECT generate_qr_code_svg('https://www.kolapsis.com');

-- Generate a QR code with a scale factor of 4
SELECT generate_qr_code_svg('https://www.kolapsis.com', 4);
```

The function accepts two parameters:
1. The content to encode in the QR code (required)
2. A scale factor to adjust the size of the SVG (optional, default is 1)

This function returns an SVG string representing the QR code for the provided text.

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

# Me

Visit my website https://www.kolapsis.com
