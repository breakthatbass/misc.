#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "llist.h"

//#include <assert.h>
// list_init: initiate a linked list
list_t *list_init(void)
{
    list_t *l = malloc(sizeof(list_t));
    if (l == NULL) {
        perror("list_init:");
        exit(EXIT_FAILURE);
    }
    l->head = NULL;
    l->nodes = 0;

    return l;
}


// new_node: create a new node
static node_t *new_node(int value, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));

    if (node != NULL) {
        node->value = value;
        node->next = next;
    }
    return node;
}



// METHODS FOR ADDING ELEMENTS

// push: add node to front of list
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

static void print_node(node_t *node) {
    printf("%d\n", node->value);
}


// append: add node to end of list
int append(list_t *l, int value)
{
    node_t *node = new_node(value, l->head);
    int success = node != NULL;
    node_t *tmp = l->head;
    node->next = NULL;

    if (!tmp)
        l->head = node;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
    l->nodes++;
    return success;
}

/*
// insert_after: insert new node after target node in list
void insert_after(list_t *list, int value, int target)
{
    // if target isn't in list, do nothing and return
    if (!exists(list, target)) return;

    node_t *node = new_node(value);

    node_t *tmp = list->head;

    while (tmp->value != target)
        tmp = tmp->next;

    node->next = tmp->next;
    tmp->next = node;
    list->nodes++;
}


// insert_before: insert new node before certain node in list
void insert_before(list_t *list, int value, int target)
{
    // if target isn't in list, do nothing and return
    if (!exists(list, target)) return;

    node_t *node = new_node(value);

    node_t *prev = NULL;
    node_t *tmp = list->head;

    // check to see if head node is the node to insert before
    if (tmp->value == target) {
        node->next = tmp;
        list->head = node;
        list->nodes++;
    } else {
        while (tmp->value != target) {
            prev = tmp;
            tmp = tmp->next;
        }

        node->next = tmp;
        prev->next = node;
        list->nodes++;
    }
}
*/

// METHODS FOR REMOVING ELEMENTS

// pop: remove and return last item in list
int pop(list_t *l)
{
    int last;
    node_t *prev = NULL;
    node_t *cur = l->head;

    while (cur) {
        if (cur->next == NULL)
            break;
        prev = cur;
        cur = cur->next;
    }

    last = cur->value;
    prev->next = NULL;

    free(cur);
    l->nodes--;
    return last;
}


// shift: remove and return first item in list
int shift(list_t *l)
{
    int first;

    node_t *tmp = l->head;
    first = tmp->value;

    l->head = tmp->next;

    free(tmp);
    l->nodes--;
    return first;
}

/*
// delete_node: delete a node form the list if it exists
void remove_node(list_t *list, int target)
{
    // if target isn't in list, do nothing and return
    if (!exists(list, target)) return;

    node_t *prev = NULL;
    node_t *cur = list->head;
    node_t *next = NULL;

    // check to see if head node is
    if (cur->value == target)
        list->head = cur->next;
    else {
        while (cur->value != target) {
            prev = cur;
            cur = cur->next;
            next = cur->next;
        }
        prev->next = next;
    }
    free(cur);
    list->nodes--;
}
*/

// destroy_list: delete and free entire list
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


// UTILITY FUNCTIONS
/*
// exists: search for node in list, return a boolean
int exists(list_t *list, int value)
{
    node_t *tmp = list->head;
    while (tmp != NULL) {
        if (tmp->value == value)
            return true;
        tmp = tmp->next;
    }
    return false;
}
*/
int search(list_t *l, int val)
{
    node_t *tmp = l->head;
}


// print: print list with position of each element
void print_list(list_t *list)
{
    node_t *tmp = list->head;
    int i = 1;

    while (tmp) {
        printf("%d: %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}


// get_size: return the number of nodes in list
size_t get_size(list_t *list)
{
    return list->nodes;
}



// SORTING FUNCTIONS

// reverse a linked list
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
