# 🧰 toolbox

A collection of utility libraries and notes.

## libs
The `libs` directory contains a collection of utility libraries to reduce time coding the same data structures or functions over and over again. The libraries mainly are to suit my own needs but anyone can use them simply by adding the `.c` file and its corresponding header file into their own project.

### libs table of contents
1. [linked list](https://github.com/breakthatbass/toolbox/tree/master/libs/lists)
2. converters
3. arrays

### Linked List
```C
// init list
list_t *list;
list_init(list);

// methods to add to list
push(list, 1);             // push a value to the front of list
append(list, 2);           // add a value to end of list 
insert_after(list, 3, 2);  // add a value after a certain element
insert_before(list, 4, 1); // add a value before a certain element

// now our list is: 4 -> 1 -> 2 -> 3 

// methods to remove from list
int x = pop(list);          // return and remove last value in list
int y = shift(list);        // return and remove first value in list
remove_node(list, 1);       // remove a node in list if it exists

// list utility functions
print_list(list);           // prints each value in list and numbers them
exists(list, 23);           // returns a bool, checks if a value is in list
int size = get_size(list);  // returns the number of elements in list

destroy_list(list);         // delete and free all nodes in list

```
