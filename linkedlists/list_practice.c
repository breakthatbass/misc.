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
  result->card = card;
  result->next = NULL;

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
  char *card_list[5] = {"counterspell", "black lotus", "giant growth", "mountain", "forest"};
  int len = sizeof(card_list)/sizeof(card_list[0]);

  node_t *head = NULL;
  node_t *temporary;


  for (int i = 0; i < len; i++)
  {
    temporary = create_new_node(card_list[i]);
    head = add_node(&head, temporary);

  }

  printlist(head);

  return 0;
}
