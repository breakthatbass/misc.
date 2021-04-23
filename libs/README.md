# libs
This is a collection of libraries and functions that I have built and used over time. I have more than what's here and I plan to add them as I have time.  

Run tests: `./runtests`
#
### [split](https://github.com/breakthatbass/toolbox/blob/master/libs/split.c)
**split a string based on delimiter(s). Similar to the Python `split` method.**  
Update: `split` no longer demolishes the original string :)  
The array must be freed after.  
utility functions:
- `int arr_len(char **a)` - returns the number of strings in the array.
- `void print_arr(char **a)` - prints each string

**Installation:**  
`curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/split.c > split.c`  
`curl https://raw.githubusercontent.com/breakthatbass/toolbox/master/libs/split.h > split.h`
```C
char *test = "hello, how, are, you, today";

char **split_test = split(test, ",");

int len = arr_len(split_test);   // 5

print_arr(split_test);
/*
* hello
* how
* are
* you
* today
*/

free(split_test);

// the original string is still usable after the split
printf("%s\n", test);  // hello, how, are, you, today
```

### linkedlist
This is a simple library for a singly linked list for integers.
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

### converter
The converter library provides functions for converting numbers to different bases. This isn't hugely useful, but it has come in handy a couple of times. The functions that return integers can return integers up to the size of `uint64_t`.

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

### To Do:
- add tests for linked list and converter
- fix mem leaks in converter
- update this readme with proper links and install scripts