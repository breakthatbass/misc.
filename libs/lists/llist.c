#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "llist.h"


// list_init: initiate a linked list
void list_init(list_t *list)
{
    list->head = NULL;
    list->nodes = 0;
}


// new_node: create a new node
static node_t *new_node(int value)
{
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        perror("new_node");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = NULL;
    return new;
}



// METHODS FOR ADDING ELEMENTS

// push: add node to front of list
void push(list_t *list, int value)
{
    node_t *node = new_node(value);

    node->next = list->head;
    list->head = node;
    list->nodes++;
}


// append: add node to end of list
void append(list_t *list, int value)
{
    node_t *node = new_node(value);

    if (list->head == NULL)
        list->head = node;
    else {
        node_t *tmp = list->head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
        list->nodes++;
    }
}


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


// METHODS FOR REMOVING ELEMENTS

// pop: remove and return last item in list
int pop(list_t *list)
{
    int last;
    node_t *prev = NULL;
    node_t *cur = list->head;

    while (cur != NULL) {
        if (cur->next == NULL) {
            // found last node in list
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    last = cur->value;
    prev->next = NULL;

    free(cur);
    list->nodes--;
    return last;
}


// shift: remove and return first item in list
int shift(list_t *list)
{
    int first;

    node_t *tmp = list->head;
    first = tmp->value;

    list->head = tmp->next;

    free(tmp);
    list->nodes--;
    return first;
}


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


// destroy_list: delete and free entire list
void destroy_list(list_t *list)
{
    node_t *cur = list->head;
    node_t *next = NULL;

    while (cur != NULL) {
        // store next
        next = cur->next;
        free(cur);
        cur = next;
    }
	// this prevents garbage values and a seg fault if destroyed list is printed
	list->head = NULL;
    list->nodes = 0;
}


// UTILITY FUNCTIONS

// exists: search for node in list, return a boolean
bool exists(list_t *list, int value)
{
    node_t *tmp = list->head;
    while (tmp != NULL) {
        if (tmp->value == value)
            return true;
        tmp = tmp->next;
    }
    return false;
}


// print: print list with position of each element
void print_list(list_t *list)
{
    node_t *tmp = list->head;
    int i = 1;

    while (tmp != NULL) {
        printf("%d: %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}


// get_size: return the number of nodes in list
int get_size(list_t *list)
{
    return list->nodes;
}
