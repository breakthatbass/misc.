#include <stdio.h>
#include <stdlib.h>

struct node
{
  char *card;
  struct node *next;
};
typedef struct node node_t;

//print
void printlist(node_t *head)
{
  node_t *temp = head;

  while (temp != NULL)
  {
    printf("%s\n", temp->card);
    temp = temp->next;
  }
}


node_t *create_new_node(char *card)
{
  node_t *result = malloc(sizeof(node_t));
  if (result != NULL)
  {
    result->card = card;
    result->next = NULL;
  }
  return result;
}

// add new node at the end of the list
node_t *add_node(node_t **head, node_t *new_node)
{
    if (*head == NULL)
    {
      new_node->next = *head;
      *head = new_node;
      return new_node;
    }
    else
    {
      node_t *tmp = *head;

      while (tmp->next != NULL)
      {
        tmp = tmp->next;
      }
        tmp->next = new_node;
    }
    return *head;
}



int main(void)
{
  char *card_list[] =
  {
    "counterspell", "black lotus", "giant growth", "mountain", "forest"
  };
  size_t len = sizeof(card_list)/sizeof(card_list[0]);

  node_t *head = NULL;
  node_t *node;


  for (size_t i = 0; i < len; i++)
  {
    node = create_new_node(card_list[i]);
    add_node(&head, node);

  }

  printlist(head);

  return 0;
}
