# 🧰 toolbox

**A collection of c utility libraries, notes, and scripts.**  

The [`libs`](https://github.com/breakthatbass/toolbox/tree/master/libs) directory contains a collection of utility libraries to reduce time coding the same data structures or functions over and over again. The libraries mainly are to suit my own needs but anyone can use them simply by clicking on the lib link below and using the install script.  

the [`notes`](https://github.com/breakthatbass/toolbox/tree/master/notes) directory contains a collection of markdown files with notes and templates on certain topics and programs I regularly reference.  

The [`scripts`](https://github.com/breakthatbass/toolbox/tree/master/scripts) directory contains some scripts that I wrote and find useful.

## Table of Contents

### libs
1. [timing.h](https://github.com/breakthatbass/toolbox/tree/master/libs#timingh) - an utlra-simple timing library all contained in a small header file. Benchmark your code quickly and easily.
2. [split](https://github.com/breakthatbass/toolbox/tree/master/libs#split) - split a string into an array of strings based on delimiter(s).
3. [linked list](https://github.com/breakthatbass/toolbox/tree/master/libs#linked-list) - a simple linked list which acts as a template containing plenty of methods.
4. [converter](https://github.com/breakthatbass/toolbox/tree/master/libs#converter) - an occasionally useful set of functions to convert between bases.
5. [minunit]() - my fork of the [minunit](https://github.com/siu/minunit) unit testing program for C programs.
6. [strlib](https://github.com/breakthatbass/toolbox/tree/master/libs#strlib) - a small string library with some useful functions not contained in `string.h`
    - `replace` - replace first instance (or all instances) of specfic char with another char.
    - `cpy_until` - copy all chars of a string up until a certain char is encountered.
    - `strafter` - search a string for a substring and return a pointer to the first char *after* the substring. Like `strstr` but returns a different pointer location.
### notes
1. [matplotlib](https://github.com/breakthatbass/toolbox/blob/master/notes/plot.md)
2. [bitwise](https://github.com/breakthatbass/toolbox/blob/master/notes/bitwise.md)
3. [pipes](https://github.com/breakthatbass/toolbox/blob/master/notes/pipes.md)
4. [getopt](https://github.com/breakthatbass/toolbox/blob/master/notes/getopt.md)
5. [threads](https://github.com/breakthatbass/toolbox/blob/master/notes/threads.md)

### scripts
1. [minunit test runner](https://github.com/breakthatbass/toolbox/blob/master/scripts/run_tests.sh)

### To Do
- add more libs
- fix dead links in this readme
- add the rest of my notes and scripts
- make this readme better
- add more tests in libs

