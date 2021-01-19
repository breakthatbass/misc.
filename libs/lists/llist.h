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


#ifndef __LLIST_H__
#define __LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

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

// init_list: initiate a linked list
void init_list(list_t *list);

// print: print list with position of each element
void print_list(list_t *list);

// exists: search for node in list, return a boolean
bool exists(list_t *list, int value);

// get_size: return the number of nodes in list
int get_size(list_t *list)


// METHODS FOR ADDING ELEMENTS

// push: add node to front of list
void push(list_t *list, int value);

// append: add node to end of list
void append(list_t *list, int value);

// insert_after: insert new node after target node in list
void insert_after(list_t *list, int value, int target);

// insert_before: insert new node before certain node in list
void insert_before(list_t *list, int value, int target);


// METHODS FOR REMOVING ELEMENTS

// pop: remove and return last item in list
int pop(list_t *list);

// shift: remove and return first item in list
int shift(list_t *list);

// delete: delete a node form the list if it exists
void remove_node(list_t *list, int target);

// destroy_list: delete and free entire list
void destroy_list(list_t *list)


#ifdef __cplusplus
}
#endif // extern "C"

#endif // __LLIST_H__
