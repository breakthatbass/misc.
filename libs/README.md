# libs docs
A collection of C libraries I've made over time. All have tests passing except `converter`.

## Run tests:   
'cd tests && ./runtests`
#
### Table of Contents:
1. [split](https://github.com/breakthatbass/toolbox/tree/master/libs#split)
2. [strlib](https://github.com/breakthatbass/toolbox/tree/master/libs#strlib)
3. [linked list](https://github.com/breakthatbass/toolbox/tree/master/libs#linked-list)
4. [timing.h](https://github.com/breakthatbass/toolbox/tree/master/libs#timingh)
5. [converter](https://github.com/breakthatbass/toolbox/tree/master/libs#converter)
6. [minunit](https://github.com/breakthatbass/toolbox/tree/master/libs#minunit)
#
## [split](https://github.com/breakthatbass/toolbox/blob/master/libs/split.c)
**split a string based on delimiter(s). Similar to the Python `split` method.**  
`Split` takes a string and turns it into an array of strings.  
Update: `split` no longer demolishes the original string :)  
The array must be freed after.  
utility functions:
- `int arr_len(char **a)` - returns the number of strings in the array.
- `void print_arr(char **a)` - prints each string

**Installation:**  
```
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/split.c > split.c  
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/split.h > split.h
```
```C
#include "split.h"

char *test = "hello, how, are, you, today";

char **split_test = split(test, ","); // also removes whitespace at beginning and end of each str

int len = arr_len(split_test);   // 5

print_arr(split_test);
/*
* hello
* how
* are
* you
* today
*/

free(split_test);  // must be freed when done

// the original string is still usable after the split
printf("%s\n", test);  // hello, how, are, you, today
```

## [strlib](https://github.com/breakthatbass/toolbox/blob/master/libs/strlib.c)
a small string library with some useful functions not contained in `string.h`.  
for more details on these functions, refer to [`strlib.h`](https://github.com/breakthatbass/toolbox/blob/master/libs/strlib.h). 

**Installation**:
```
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/strlib.c > strlib.c
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/strlib.h > strlib.h
```
```C
#include "strlib.h"

char *s = "hello, how are you";

// copy a string until a certain char is encountered

char dest[20];
cpy_until(dest, s, ',');
puts(dest)  // "hello"

// replace first instance of char 'o' with 'z' in string s
replace(s, 'o', 'x', FIRST);
puts(s);    // "hellx, how are you"

// reaplce all instances of char 'o' with 'z' in string s
replace(s, 'o', 'x', ALL);
puts(s)     // "hellx, hxw are yxu"

// search a string for a substring and return a pointer to after the substring
char *haystack = "db_type: sql"
char *tmp = strafter(haystack, "db_type: ");
puts(tmp);  // "sql"

```

## [linked list](https://github.com/breakthatbass/toolbox/blob/master/libs/llist.c)
This is a simple library for a singly linked list for integers. I really use it as a template and copy over only functions I need. It has a reverse function too for all your l33tc0de needs. for more details on these functions, refer to [`llist.h`](https://github.com/breakthatbass/toolbox/blob/master/libs/llist.h).

**Installation**:
```
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/llist.c > llist.c
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/llist.h > llist.h
```
```C
#include "llist.h"

// init list
list_t *list = list_init();

// methods to add to list
push(list, 1);             // push a value to the front of list
append(list, 2);           // add a value to end of list

// let's add a few more elements
append(list, 3);
append(list, 4);
append(list, 5);
append(list, 6);

// list: [1, 2, 3, 4, 5, 6]

// methods to remove from list
int x = pop(list);          // return and remove last value in list
int y = shift(list);        // return and remove first value in list

if (remove_node(list, 3) > -1)
    printf("node was found and removed\n");
else
    printf("node was not found in list");

// now our list is: [2, 4, 5]

// searching a list
if (search(list, 2) > -1)
    printf("2 is in the list!!\n");

// list utility functions
print_list(list);           // prints each value in list and numbers them

int size = get_size(list);  // returns the number of elements in list

// bro, do you even l33tc0de?
reverse(list);

destroy_list(list);         // clean up when done

```

## [timing.h](https://github.com/breakthatbass/toolbox/blob/master/libs/timing.h)
`Timing.h` is an ultra-simple timing library for benchmarking code. It doesn't have any options, it just times your code and saves the time as a float in the `timing` struct.  

Just inlcude the `timing.h` header file after copying it over to your project directory and you're good to go. 

**Installation**:  
`curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/timing.h > timing.h`

```C
#include "timing.h"


timing t;

start_timing(&t);

// block of code to time...

end_timing(&t);

printf("total time: %f\n". t.ttime);    // total time: 6.227586

```

## [converter](https://github.com/breakthatbass/toolbox/blob/master/libs/converter.c)
The converter library provides functions for converting numbers to different bases. This isn't hugely useful, but it has come in handy a couple of times. The functions that return integers can return integers up to the size of `uint64_t` or `long long`.  

**Installation**:
```
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/converter.c > converter.c
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/converter.h > converter.h
```

```C
// binary to decimal
int x = btod("010101");  // returns 21

// decimal to binary
char *bin = dtob(x);  // returns "010101"

// binary to hex
char *hex = btoh("1011111011101111");  // returns "BEEF"

// hex to decimal
int hdec = htod("BEEF");  // returns 48879
```

## [minunit](https://github.com/breakthatbass/toolbox/blob/master/libs/minunit.h)
This is my fork of minunit, the C unit testing library. I added colors to more easily see where programs fail and pass. For documentation, refer to the [repo](https://github.com/breakthatbass/minunit).  

**Installation**:
```
curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/minunit.h > minunit.h
```
