# 🧰 toolbox

**A collection of c utility libraries, notes, and scripts.**  
This repo contains things that I regularly refer to in writing code whether it be libraries or notes or templates. Besides this repo, I also constantly refer to [*The C Programming Language*](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628), [*Advanced Programming in the UNIX Environment*](https://www.amazon.com/Advanced-Programming-UNIX-Environment-3rd/dp/0321637739/ref=sr_1_1?crid=2NN6COWGMBAIA&dchild=1&keywords=advanced+programming+in+the+unix+environment&qid=1621436787&s=books&sprefix=Advanced+programmin%2Cstripbooks%2C172&sr=1-1), and occasionally [*The Practice of Programming*](https://www.amazon.com/Practice-Programming-Addison-Wesley-Professional-Computing/dp/020161586X/ref=sr_1_1?crid=2YJUQ6BB5LMOP&dchild=1&keywords=the+practice+of+programming&qid=1621436871&s=books&sprefix=the+practice+of+programming%2Cstripbooks%2C286&sr=1-1). Do *you* own those books yet??

The [`libs`](https://github.com/breakthatbass/toolbox/tree/master/libs) directory contains a collection of libraries I've made over time. Most of are tested and bug free (until I find more bugs). Docs for each lib is in the `libs` directory as well as simple install scripts for generating the files in your project.

the [`notes`](https://github.com/breakthatbass/toolbox/tree/master/notes) directory contains a collection of markdown files with notes and templates on certain topics and programs I regularly reference.  

The [`scripts`](https://github.com/breakthatbass/toolbox/tree/master/scripts) directory contains some scripts that I wrote and find useful.

## Table of Contents

### libs
1. [timing.h](https://github.com/breakthatbass/toolbox/tree/master/libs#timingh) - ultra-simple timing library contained in a small header file. Benchmark your code quickly and easily.
2. [split](https://github.com/breakthatbass/toolbox/tree/master/libs#split) - split a string into an array of strings based on delimiter(s).
3. [linked list](https://github.com/breakthatbass/toolbox/tree/master/libs#linked-list) - a simple linked list which acts as a template containing plenty of methods.
4. [converter](https://github.com/breakthatbass/toolbox/tree/master/libs#converter) - an occasionally useful set of functions to convert between bases.
5. [minunit]() - my fork of the [minunit](https://github.com/siu/minunit) unit testing program for C programs.
6. [strlib](https://github.com/breakthatbass/toolbox/tree/master/libs#strlib) - a small string library with some useful functions not contained in `string.h`.

### scripts
1. [notes-py](https://github.com/breakthatbass/toolbox/tree/master/scripts/notes-py) - my personal ultra-simple `man` pages cli for things I always forget but always need. 
2. [minunit test runner](https://github.com/breakthatbass/toolbox/blob/master/scripts/run_tests.sh) - put this script in your tests dir and it'll compile each minunit test, run each one, clean up the binaries, and give a total time.


### notes
1. [matplotlib](https://github.com/breakthatbass/toolbox/blob/master/notes/plot.md) - easily generate graphs with python's matplotlib library. wicked easy.
2. [bitwise](https://github.com/breakthatbass/toolbox/blob/master/notes/bitwise.md) - still working on bit manipulation. here's what I have for now.
3. [pipes](https://github.com/breakthatbass/toolbox/blob/master/notes/pipes.md) - I often forget the small details of using pipes. these notes prevent me from having to think too hard.
4. [getopt](https://github.com/breakthatbass/toolbox/blob/master/notes/getopt.md) - CLI interface library. i always forget how to set it up. just copy and paste this and you're ready to go.
5. [threads](https://github.com/breakthatbass/toolbox/blob/master/notes/threads.md) - some quick thread notes to reference.


### To Do
- fix memory issues in converter lib
- add tests for converter

