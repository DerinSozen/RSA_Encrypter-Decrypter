# RSA Encoder/Decoder

This is a personal project to demonstrate my knowledge of Discrete math from CS173 and personal passions in encryption and modular arithmetic Theory

It accepts a message and a passphrase, using the passphrase to encrypt the message

Prime numbers are generated using the Sieve Of Eratosthenes algorithm

## Usage

```C++
./main
```
 When calling, make sure to either specify encryption or decryption with the flags "--encrypt" or "--decrypt"

This program is only designed to handle argument and will not work with other use cases

**Examples:**
```C++
./main --encrypt
```
```C++
./main --decrypt
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
## License
MIT License

Copyright (c) 2023 Derin Sözen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

