#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXLEN 50

struct node
{
    int value;
    struct node *next;
}; 
typedef struct node node_t;


// new_node: creates new node for list
static node_t *new_node(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value; 
    node->next = NULL;

    return node;
}


// push: add node to front of list
static void push(node_t **head, int value)
{
    node_t *node = new_node(value);

    node->next = *head;
    *head = node;
}


// append: add node to end of list
static void append(node_t **head, int value)
{
    node_t *node = new_node(value);

    if (*head == NULL) {
        node->next = *head;
        *head = node;
    } else {
        node_t *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}


// reverse: rearrange pointers to reverse list
static void reverse(node_t **head)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        // store next node
        next = current->next;
        // reverse current node's pointer
        current->next = prev;
        // move pointers one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}


// insert_after: insert new node after certain node in list
static void insert_after(node_t **head, int value, int insert_after)
{
    node_t *node = new_node(value);

    node_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->value == insert_after) {
            node->next = tmp->next;
            tmp->next = node;
        }
        tmp = tmp->next;
    }
}


// insert_before: insert new node before certain node in list
static void insert_before(node_t **head, int value, int insert_before)
{
    node_t *node = new_node(value);

    node_t *prev = NULL;
    node_t *tmp = *head;

    // check to see if head node is the node to insert before
    if (tmp->value == insert_before) {
        node->next = *head;
        *head = node;
    } else {
        while (tmp != NULL) {
            if (tmp->value == insert_before) {
                node->next = tmp;
                prev->next = node;
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }
}


// exists: search for node in list, return a boolean
static bool exists(node_t **head, int data)
{
    node_t *tmp = *head;
    while (tmp != NULL) {
        if (tmp->value == data)
            return true;
        tmp = tmp->next;
    }
    return false;
}


// pop: remove and return node->value from end of list
int pop(node_t **head)
{
    int last;
    node_t *prev = NULL;
    node_t *current = *head;

    while (current != NULL) {
        if (current->next == NULL) {
            // found last node in list
            break;
        }
        prev = current;
        current = current->next;
    }

    last = current->value;
    prev->next = NULL;

    free(current);
    
    return last;
}


// delete_node: delete a node form the list if it exists
static void delete_node(node_t **head, int value)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        // store next
        next = current->next;
        if (current->value == value) {
            prev->next = next;
            free(current);
        }
        prev = current;
        current = next;
    }
}


// destroy: delete and free entire list
static void destroy(node_t **head)
{
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        // store next
        next = current->next;
        current->next = NULL;
        free(current);
        current = next;
    }
}


// print: print list with position of each element
static void print(node_t *head)
{
    node_t *tmp = head;
    int i = 1;

    while (tmp != NULL)
    {
        printf("%d: %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}


int main(int argc, char **argv)
{
    node_t *head = NULL;

    print(head);

    append(&head, 15);
    push(&head, 23);
    push(&head, 22);
    push(&head, 21);
    append(&head, 35);
    print(head);

    printf("reversing list...\n");
    reverse(&head);
    print(head);

    printf("insert 100 after 15\n");
    insert_after(&head, 100, 15);
    print(head);

    printf("insert 12 before 21\n");
    insert_before(&head, 12, 21);
    print(head);

    printf("exists: searching for node 100 and 79\n");
    bool yes = exists(&head, 100);
    bool no = exists(&head, 79);
    printf("100: %d\n", yes);
    printf("79: %d\n", no);

    printf("popping!\n");
    int last_el = pop(&head);
    printf("popped element: %d\n", last_el);
    print(head);

    printf("deleting 100\n");
    delete_node(&head, 100);
    print(head);

    printf("destroying list\n");
    destroy(&head);
    print(head);

    return 0;
}
