/******************************************************************************
*
*   Author: Taylor Gamache
*   Email: gamache.taylor@gmail.com
*
*   Version: 0.1.2
*
*   License: MIT 2020
*
******************************************************************************/


#ifndef LLIST_H__
#define LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node_t;

struct list {
    node_t *head;
    size_t nodes;
};
typedef struct list list_t;


// LINKED LIST API

//void list_init(list_t *list);
list_t *list_init(void);

// print: print list with position of each element
void print_list(list_t *list);

// get_size: return the number of nodes in list
size_t get_size(list_t *list);


// METHODS FOR ADDING ELEMENTS

// push: add node to front of list
int push(list_t *list, int value);

// append: add node to end of list
int append(list_t *list, int value);


// METHODS FOR REMOVING ELEMENTS

// pop: remove and return last item in list
int pop(list_t *list);

// shift: remove and return first item in list
int shift(list_t *list);

// delete: delete a node form the list if it exists
int remove_node(list_t *list, int target);

// destroy_list: delete and free entire list
void destroy_list(list_t *list);

// METHODS FOR SORTING

// reverse a list
void reverse(list_t *l);

int search(list_t *l, int val);

int remove_node(list_t *l, int target);

#ifdef __cplusplus
}
#endif // extern "C"

#endif // __LLIST_H__
