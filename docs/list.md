# [linked list](https://github.com/breakthatbass/c-libs/blob/master/src/llist.c) documentation
a simple singly linked list lib for integers. 

#
## creating a list:
<br>

```C
#include "llist.h"

list_t *list_init(void);
```
- allocate memory and create an empty list.
- **returns** a pointer to an empty list or, if `malloc` fails, `NULL`.
#
## adding to list:

```C
int push(list_t *l, int int_to_push)
```
- adds `int_to_push` to front of list.
- **returns** 0 if `malloc` fails, else 1.

<br>

```C
int append(list_t *l, int int_to_append)
```
- adds `int_to_append` to end of list.
- **returns** 0 if `malloc` fails, else 1.
#
## removing from list:

```C
int pop(list_t *l)
```
- removes first item from list.
- **returns** value of first item or, if list is empty, -1.

<br>

```C
int shift(list_t *l)
```
- removes last item from list.
- **returns** value of last item or, if list is empty, -1.

<br>

```C
int remove_node(list_t *l, int int_to_remove);
```
- searches a list for `int_to_remove` and deletes node if found.
- **returns** value of node if `int_to_remove` is found, else returns -1.

#
## misc. list functions:

```C
int get_size(list_t *l)
```
- **returns** the number of elements in a list.

<br>

```C
void print_list(list_t *l)
```
- prints out the value of each node in list.

<br>
 
```C
int search(list_t *l, int int_to_search_for)
```
- searches a list for `int_to_search_for`.
- **returns** value of node if int_to_search_for is in list, else returns -1.

<br>

```C
void sort_list(list_t *l)
```
- sorts a list of ints from least to greatest.
- **note:** this function changes original list.

<br>

```C
void reverse(list_t *l)
```
- reverse a list and look great in an interview.
- **note:** this function changes original list.

<br>

```C
void destroy_list(list_t *l);
```
- delete and free list and all nodes