# Advanced Programming in the UNIX Environment 2nd Edition
## Notes and Demos

This program is an all-in-one program, convinient for running code snippet in the book.

Visit [http://libpix.org/apue](http://libpix.org/apue) for notes and documents.

Bug report [yang@libpix.org](mailto:yang@libpix.org)

## Usage
In the source code path, run

    $ ./configure  
    $ make  

Now, you should get the binary executable, run

    $ ./apue

to get the list of programs.

    Programs:
     ls1             1.3    List all the files in a directory
     mycat           1.4    Copy standard input to standard output
     getcputc        1.5    Copy standard input to standard output, using standard I/O
     hello           1.6    Print the process ID
     testerror       1.8    Demonstrate strerror and perror
     uidgid          1.9    Print user ID and group ID
     shell2          1.10   Read commands from standard input and execute them
     conf            2.13   Print all possible sysconf and pathconf values
    ...

To run a program you want, for example, ls1, you can type

    $ ./apue ls1 .

or you can use the figure number

    $ ./apue 1.1 .

the most convinient way is to use symbolic link

    $ ln -s apue ls1

then you can run

    $ ./ls1 .

Some library functions have multiple versions, run

    $ ./apue -f

to get the list of library functions.

    Functions:
     path_alloc      2.15   Dynamically allocate space for a pathname
     open_max        2.16   Determine the number of file descriptors
     set_fl          3.11   Turn on one or more of the file status flags for a descriptor
     pr_exit         8.5    Print a description of the exit status
     # system        8.22   The system function, without signal handling
                     10.28  Correct POSIX.1 implemetation of system function
     # sleep         10.7   Simple, incomplete implementation of sleep
                     10.8   Another (imperfect) implementation of sleep
                     10.29  Reliable implementation of sleep
     ...


Functions start with '#' are multi-version functions.  
Use environment variable to specify the function.  
For example, 

    $ system=8.22 ./apue systest1

if you want to use the ansi c version in libc, run

    $ system=ansi ./apue systest1

## License

The MIT License (MIT)

Copyright (c) 2014 Martin Y. Yang

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


