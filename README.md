# Advanced Programming in the UNIX Environment 2nd Edition
## Notes and Demos

This program is an all-in-one program, convinient for running code snippet in the book.

Visit [http://libpix.org/apue](http://libpix.org/apue) for notes and documents.

Bug report [yang@libpix.org](mailto:yang@libpix.org)

## Usage
To build, just run

    $ ./configure
    $ ./make

After that, get the list of programs

    $ ./apue

Then you can run a program, for example, ls1, by running

    $ ./apue ls1 .

or use the figure number

    $ ./apue 1.3 .

A better way to use is to make a symbolic

    $ ln -s apue ls1
    $ ./ls1 .

Some library functions may have different version, you can specify version by environ variable

    $ system=8.22 ./apue systest1

Or for the function name is ansi c library function , you can specify use the libc implementation

    $ system=ansi ./apue systest1

## License

The MIT License (MIT)

Copyright (c) 2014 Martin Y. Yang

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


