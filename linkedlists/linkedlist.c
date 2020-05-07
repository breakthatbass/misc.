#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head)
{
  node_t *temporary = head;

  while (temporary != NULL)
  {
    printf("%d - ", temporary->value);
    temporary = temporary->next;
  }
  printf("\n");
}

node_t *create_new_node(int value)
// this creates a new node in the linked list
// adds to end of the list
{
  // allocate memory for a new node
  node_t *result = malloc(sizeof(node_t));
  // set the value of the node to argument of function
  result->value = value;
  // for now, just set it to point to nothing
  result->next = NULL;
  return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
  // have node_to_insert point to the head
  node_to_insert->next = *head;
  // now have the head point to the node_to_insert
  *head = node_to_insert; // having this pointer requires the **head parameter
  return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
  newnode->next = node_to_insert_after->next;
  node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value)
{
  node_t *tmp = head;
  while (tmp != NULL)
  {
    if (tmp->value == value) {
      return tmp;
    }
    tmp = tmp->next;
  }
  return NULL;
}

int main()
{

  /* create list through loop and functions *********/

  node_t *head = NULL;
  node_t *tmp;

  for (int i = 0; i < 25; i++)
  {
    tmp = create_new_node(i);
    head = insert_at_head(&head, tmp);
  }

  tmp = find_node(head, 13);
  printf("found node with value %d\n", tmp->value);

  insert_after_node(tmp, create_new_node(75));

  printlist(head);

// below is commented out so the above code will compile
// it shows more manual ways to build a linked list

  /* manually create the list *************/
/*
  node_t n1, n2, n3; // establish nodes...just three for now
  node_t *head; // establish the head (starting point of list)

  // set values for each node
  n1.value = 45;
  n2.value = 8;
  n3.value = 32;

  // link them up
  // head = &n1; // set the head to point to the address of n1
  n1.next = &n2; // set node n1 to point to node n2 (next node in list)
  n2.next = &n3; // n2 to point to n3
  n3.next = NULL; // set the last element in the list to point to NULL - indicating the end of the list

*/
  /* create list using the create_new_node function from above...still somewhat manual */

/*
  node_t *head; // establish starting point
  node_t *tmp; // create temp var for setting and adding to list

  tmp = create_new_node(32);
  head = tmp; // set the node created as the beginning of list
  tmp = create_new_node(8); //add another node
  tmp = next->head; // make 8 point to head (32)
  head = tmp; //now set 8 to head
  tmp = create_new_node(34);
  tmp = next->head;
  head = tmp;
*/

  return 0;
}
