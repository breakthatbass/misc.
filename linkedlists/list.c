/** 
 * usage: compile and run with nums.txt as argument
 * nums.txt is in the directory
 * 
 * */

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


// creat_new_node: creates new node for list.
static node_t *create_new_node(int value)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value; 
    new_node->next = NULL;

    return new_node;
}


//add_node: append new node on to list
static node_t *add_node(node_t **head, node_t *new_node)
{
    if (*head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    } else {
        node_t *tmp = *head;
        while (tmp->next != NULL) 
            tmp = tmp->next;
        tmp->next = new_node; 
    }
    return *head;
}



static node_t *push(node_t **head, node_t *pushval)
{
    pushval->next = *head;
    *head = pushval;
    return pushval;
}



static void reverse_list(node_t **head)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        // store next
        next = current->next;
        // reverse current node's pointer
        current->next = prev;
        // move pointers one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}



static void insert_after(node_t *prev_node, node_t *new_node)
{
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}



static node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}


// load_file: take a file of nums and load them into list
static node_t *load_file(char *file)
{
    FILE *fp;
    char buffer[MAXLEN];
    node_t *head;
    node_t *node;

    fp = fopen(file, "r");
    if (fp == NULL) {
      fprintf(stderr, "Could not open file %s\n", file);
      exit(EXIT_FAILURE);
  }

  head = NULL;
  // take each value from file, load it into a buffer
  while (fgets(buffer, sizeof(node_t), fp)) {
      // make sure it's not a text file
      if (isalpha(buffer[0])) {
          fprintf(stderr, "error: problem with file\n");
          exit(EXIT_FAILURE);
      }
      // convert value to int, put it in a node
      node = create_new_node(atoi(buffer));
      // append node to list
      push(&head, node);
  }
  fclose(fp);
  return head;
}



static void printlist(node_t *head)
{
    node_t *tmp = head;

    while (tmp != NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}



int main(int argc, char **argv)
{
    char *file;
    
    file = argv[1];

    node_t *list = load_file(file);
    reverse_list(&list);
    printlist(list);

    return 0;
}
