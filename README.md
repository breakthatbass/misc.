# 🧰 toolbox

A collection of utility libraries and notes.

## libs
The `libs` directory contains a collection of utility libraries to reduce time coding the same data structures or functions over and over again. The libraries mainly are to suit my own needs but anyone can use them simply by adding the `.c` file and its corresponding header file into their own project.

### libs table of contents
1. linked list
2. converters
3. arrays

### Linked Lists
```C
// init list
list_t *list;
list_init(list);

// methods to add to list
push(list, 1);             // push a value to the front of list
append(list, 2);           // add a value to end of list
insert_after(list, 3, 2);  // add the value 3 after 2
insert_before(list, 4, 1); // add the value 4 before 1

// now our list is: 4 -> 1 -> 2 -> 3 

// methods to remove from list
int x = pop(list);          // return and remove last value in list
int y = shift(list);        // return and remove first value in list
remove_node(list, 1);       // remove a node in list if it exists

// now our list is: 2

// list utility functions
print_list(list);           // prints each value in list and numbers them
exists(list, 23);           // returns a bool, checks if a value is in list
int size = get_size(list);  // returns the number of elements in list

destroy_list(list);         // delete and free all nodes in list

```

### Converter
The converter library provides functions for converting numbers to different bases. This isn't hugely useful, but it has come in handy a couple of times. The functions tha return integers can return integers up to the size of `uint64_t`.

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

### Split
`split()` splits a string into an array of strings based on a delimiter.

```C
char str[50];
char *test = "hello, how, are, you, today";

strcpy(str, test);

char **new_arr = split(str, ",");

int len = arr_len(new_str);   // 5

print_arr(new_arr);
/* 
* hello
* how
* are
* you
* today
*/

```