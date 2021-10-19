/***************************************************************************
 *
 * Author: Taylor Gamache
 * Email: gamache.taylor@gmail.com
 * url: https://github.com/breakthatbass/c-libs
 *
 * Version: 1.0.2
 * License: MIT 2020
 *
 * @name: Int Linked List
 * @description: a simple singly list of ints for stacks & queues.
 *
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "llist.h"


/* *
 * list_init
 *
 * @desc: creates an empty linked list.
 * @return: a potiner to the head of list (type `list_t`).
 * */
list_t *list_init(void)
{
    list_t *l = malloc(sizeof(list_t));
    if (l) {
        l->head = NULL;
        l->nodes = 0;
    }
    return l;
}


// new_node: allocate space for a new node and return that node
static node_t *new_node(int value, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));

    if (node != NULL) {
        node->value = value;
        node->next = next;
    }
    return node;
}


/************************************************
 * ADDING ELEMENTS TO LIST
 ***********************************************/

/* *
 * push
 *
 * @desc: add a node to the front of the list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @param: `value` - the int value to push to the list.
 * @return: `1` if successful, `0` if allocation for node failed.
 * */
int push(list_t *l, int value)
{
    node_t *node = new_node(value, l->head);
    int success = node != NULL;

    if (success) {
        l->head = node;
        l->nodes++;
    }
    return success;
}


/* *
 * append
 *
 * @desc: add a node to the end of the list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @param: `value` - the int value to append to the list.
 * @return: `1` if successful, `0` if allocation for node failed.
 * */
int append(list_t *l, int value)
{
    node_t *node = new_node(value, l->head);
    int success = node != NULL;
    node_t *tmp = l->head;
    node->next = NULL;

    if (!l->head) {
        l->head = node;
		l->head->next = NULL;
	} else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
    l->nodes++;
    return success;
}

/************************************************
 * REMOVING ELEMENTS FROM LIST
 ***********************************************/


/* *
 * shift
 *
 * @desc: remove the last node from a list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @return: value stored in the last node.
 * */
int shift(list_t *l)
{
    int last = -1;
    node_t *p = l->head;
    node_t *prev = NULL;

	// empty list
	if (get_size(l) == 0)
		return last;
	else if (get_size(l) == 1) {
        last = p->value;
        l->head = NULL;
    } else {
        while (p->next) {
            prev = p;
            p = p->next;
        }
        last = p->value;
        prev->next = NULL;
    }
    free(p);
    l->nodes--;
    return last;
}


/* *
 * pop
 *
 * @desc: remove first node in a list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @return: vlaue stored in the first node.
 * */
int pop(list_t *l)
{
    int first = -1;
	
	if (get_size(l) == 0)
		return first;

    node_t *tmp = l->head;
    first = tmp->value;

    l->head = tmp->next;

    free(tmp);
    l->nodes--;
    return first;
}


/* *
 * remove_node
 *
 * @desc: remove a node with a certain value from a list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @param: `target` - the `int` to delete.
 * @return: `1` if `target` is found in list, else `-1`.
 * */
int remove_node(list_t *l, int target)
{
    node_t **p = &l->head;
    node_t *tmp = NULL;

    while((*p)->next && (**p).value != target)
        p = &(*p)->next;
    if ((*p)->value == target) {
        tmp = *p;
        *p = tmp->next;
        free(tmp);
        l->nodes--;
        return 1;
    }
    return -1;
}



/************************************************
 * UTILITY FUNCTIONS
 ***********************************************/

/* *
 * search
 *
 * @desc: do a linear search in a list.
 *
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @param: `target` - value to be search for.
 * @return: `target` if `target` is found in list, else `-1`.
 * */
int search(list_t *l, int target)
{
    node_t **p = &l->head;
    while((*p)->next && (*p)->value != target)
        p = &(*p)->next;

    if ((*p)->value == target)
        return target;
    return -1;
}


/* *
 * destroy_list
 *
 * @desc: free all nodes in a list and the `list_t` head pointer.
 * @param: `*l` - a pointer to a list of type `list_t`.
 **/
void destroy_list(list_t *l)
{
    node_t *cur = l->head;
    node_t *next = NULL;

    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(l);
}


/* *
 * print_list
 *
 * @desc: print the value at each node in a list and number them.
 * @param: `*l` - a pointer to a list of type `list_t`.
 * */
void print_list(list_t *l)
{
    node_t *tmp = l->head;
    int i = 1;

    while (tmp) {
        printf("%d: %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}


/* *
 * get_size
 *
 * @desc: get the number of nodes in a list.
 * @param: `*l` - a pointer to a list of type `list_t`.
 * @return: the number of nodes in `list`.
 * */
size_t get_size(list_t *list)
{
    return list->nodes;
}


/* *
 * reverse
 *
 * @desc: reverse a list & look great in an interview.
 * @param: `*l` - a pointer to a list of type `list_t`.
 * */
void reverse(list_t *l)
{
    node_t *prev = NULL;
    node_t *cur = l->head;
    node_t *next = l->head;

    while (cur) {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    l->head = prev;
}


/* for use in the sort function below */
static int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/* *
 * sort_list
 *
 * @desc: sort a list based on the values from least to greatest.
 * @param: `*l` - a pointer to a list of type `list_t`.
 * */
void sort_list(list_t *l)
{
    // check if list is empty
    if (l->nodes == 0) return;

    // create array to hold each element in list
    int list_size = l->nodes;
    int *tmp_array = malloc(sizeof(int)*list_size);
    if (tmp_array == NULL) return;

    // load elements one by one into array
    node_t *tmp = l->head;
    int i = 0;
    while (tmp) {
        *tmp_array++ = tmp->value;
        tmp = tmp->next;
        i++;
    }
    tmp_array -= i;

    // qsort it
    qsort(tmp_array, list_size, sizeof(int), cmpfunc);
    
    // go through each element in list and reassign each node from array
    i = 0;
    tmp = l->head;
    while (tmp) {
        tmp->value = *tmp_array++;
        tmp = tmp->next;
        i++;
    }
    tmp_array -= i;
    free(tmp_array);
}


