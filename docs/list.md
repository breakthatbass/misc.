# [linked list](https://github.com/breakthatbass/toolbox/blob/master/llist.c)
This is a simple library for a singly linked list for integers. 

This is the most common list structure I use. It has functions for both stacks and queues. Outside of this my lists tend to be customized for the context rather than a one size fits all. Either way, I sort of use this as a template to work from.  

For more documentation see [`llist.h`](https://github.com/breakthatbass/toolbox/blob/master/llist.h).


## Getting Started:

<br>

```C
#include "llist.h"

// make a stack and a queue
list_t *stack = list_init();
list_t *queue = list_init();

// memory is allocated so it's good to check for NULL after init
assert(stack);
assert(queue);
```
#
## adding to list:
memory is allocated for a node when a new one is created. If `malloc` fails, `push` and `pop` will return 0, otherwise 1 is returned.

```C
// add to stack
push(stack, 1);
push(stack, 2);
push(stack, 3);
push(stack, 4);

// add to queue
append(queue, 1);
append(queue, 2);
append(queue, 3);
append(queue, 4);

// stack is [4, 3, 2, 1]
// queue is [1, 2, 3, 4]
```
#
## removing from list:

```C
// remove front node of list and return its value
int popped_int = pop(queue); // returns 1, queue is now 3 items

// remove last node of list and return its value
int last_int = shift(queue); // returns 4, queue is now 2 items
```
#
## misc. list functions:

```C
// GETTING SIZE:
int stack_size = get_size(stack);   // returns 3

// PRINTING:
print_list(stack);
/*
*   result:
*   1: 4
*   2: 3
*   3: 2
*   4: 1
*/



// SEARCHING: 
int search(list_t *l, int int_to_search_for)

// returns the number to search for if found
// else returns -1
int search_queue_for_4 = search(queue, 4);

if (search_queue_for_4) == -1)
    printf("4 is not in the list\n");
else if (search_queue_for_4 == 4)
    printf("4 is in the list");
else
    printf("there might be a bug if you see this message\n");



// REMOVING SPECIFIC NODES:
int remove_node(list_t *l, int int_to_remove);

// searches list for int. if found, returns that int and deletes node
// else returns -1
int removed_node_int = remove_node(queue, 3);

if (removed_node_int == -1) {
    printf("3 is not in list so no nodes were removed\n");
else if (removed_node_int = 3)
    printf("3 was found and removed from list\n");
else
    printf("there might be a bug if you see this message\n");
}



// sorting a list
sort_list(stack);
// stack is now [1, 2, 3, 4]

// reversing a list for when you're in an interview
reverse(stack);
// stack is now [4, 3, 2, 1]



// clean up
destroy_list(stack);
destroy_list(queue);
```