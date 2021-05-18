#include <stdio.h>
#include <stdlib.h>

#include "llist.h"


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


// UTILITY FUNCTIONS

// slow linear search algorithm
int search(list_t *l, int target)
{
    node_t **p = &l->head;
    while((*p)->next && (*p)->value != target)
        p = &(*p)->next;

    if ((*p)->value == target)
        return target;
    return -1;
}

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


// print: print list with position of each element
void print_list(list_t *list)
{
    node_t *tmp = l->head;
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
