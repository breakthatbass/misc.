#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 50

struct node
{
    int value;
    struct node *next;
}; 
typedef struct node node_t;

struct list {
	int len;
	node_t *head;
};
//typedef struct list List;

static node_t *new_node(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;

    return node;
}

static void print(void)
{
    node_t *head = struct list->head->value;

}

int main()
{

}