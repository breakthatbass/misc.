# Int Linked List documentation
a simple singly list of ints for stacks & queues.
 
#
```C
list_t *list_init(void) 
```
creates an empty linked list.
- **returns** a potiner to the head of list (type `list_t`).

<br>

```C
int push(list_t *l, int value) 
```
add a node to the front of the list.
- `*l` - a pointer to a list of type `list_t`.
- `value` - the int value to push to the list.
- **returns** `1` if successful, `0` if allocation for node failed.

<br>

```C
int append(list_t *l, int value) 
```
add a node to the end of the list.
- `*l` - a pointer to a list of type `list_t`.
- `value` - the int value to append to the list.
- **returns** `1` if successful, `0` if allocation for node failed.

<br>

```C
int shift(list_t *l) 
```
remove the last node from a list.
- `*l` - a pointer to a list of type `list_t`.
- **returns** value stored in the last node.

<br>

```C
int pop(list_t *l) 
```
remove first node in a list.
- `*l` - a pointer to a list of type `list_t`.
- **returns** vlaue stored in the first node.

<br>

```C
int remove_node(list_t *l, int target) 
```
remove a node with a certain value from a list.
- `*l` - a pointer to a list of type `list_t`.
- `target` - the `int` to delete.
- **returns** `1` if `target` is found in list, else `-1`.

<br>

```C
int search(list_t *l, int target) 
```
do a linear search in a list.
- `*l` - a pointer to a list of type `list_t`.
- `target` - value to be search for.
- **returns** `target` if `target` is found in list, else `-1`.

<br>

```C
void print_list(list_t *l) 
```
free all nodes in a list and the `list_t` head pointer.
- `*l` - a pointer to a list of type `list_t`.
print the value at each node in a list and number them.
- `*l` - a pointer to a list of type `list_t`.

<br>

```C
size_t get_size(list_t *list) 
```
get the number of nodes in a list.
- `*l` - a pointer to a list of type `list_t`.
- **returns** the number of nodes in `list`.

<br>

```C
void reverse(list_t *l) 
```
reverse a list & look great in an interview.
- `*l` - a pointer to a list of type `list_t`.

<br>

```C
void sort_list(list_t *l) 
```
sort a list based on the values from least to greatest.
- `*l` - a pointer to a list of type `list_t`.

<br>

