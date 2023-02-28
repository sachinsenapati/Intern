#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
} Node;
void
add_first (Node ** head, int data)
{
  Node *new_node = malloc (sizeof (Node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void
print_list (Node * head)
{
  Node *current = head;
  while (current != NULL)
    {
      printf ("%d ", current->data);
      current = current->next;
    }
  printf ("\n");
}

void
reverse_list (Node ** head)
{
  Node *prev = NULL;
  Node *current = *head;
  Node *next = NULL;
  while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  *head = prev;
}

/*
int main() {
 Node *head = NULL;
 add_first(&head, 5);
 add_first(&head, 4);
 add_first(&head, 3);
 add_first(&head, 2);
 add_first(&head, 1);
 printf("List before reversing: ");
 print_list(head);
 reverse_list(&head);
 printf("List after reversing: ");
 print_list(head);
 return 0;
}
*/
int main ()
{
  node *head = malloc (sizeof (node));
  head->data = 1;
  head->next = malloc (sizeof (node));
  head->next->data = 2;
  head->next->next = malloc (sizeof (node));
  head->next->next->data = 3;
  head->next->next->next = NULL;
  printf ("List before reversing: ");
  print_list (head);
  reverse_list (&head);
  printf ("\nList after reversing: ");
  print_list (head);
  return 0;
}
