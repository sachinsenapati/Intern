#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
} node;
void print_list_recursive (node * head)
{
  if (head == NULL)
    {
      printf ("List is empty\n");
    }
  else
    {
      printf ("%d ", head->data);
      print_list_recursive (head->next);
    }
}

void print_list (node * head)
{
  if (head == NULL)
    {
      printf ("List is empty\n");
    }
  else
    {
      node *current = head;
      while (current != NULL)
	{
	  printf ("%d ", current->data);
	  current = current->next;
	}
    }
}

void add_first (node ** head, int data)
{
  node *new_node = malloc (sizeof (node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void add_last (node ** head, int data)
{
  node *new_node = malloc (sizeof (node));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL)
    {
      *head = new_node;
    }
  else
    {
      node *current = *head;
      while (current->next != NULL)
	{
	  current = current->next;
	}
      current->next = new_node;
    }
}

void delete_node (node ** head, int data)
{
  node *current = *head;
  node *prev = NULL;
  while (current != NULL && current->data != data)
    {
      prev = current;
      current = current->next;
    }
  if (current == NULL)
    {
      printf ("Element not found in list\n");
      return;
    }
  if (prev == NULL)
    {
      *head = current->next;
    }
  else
    {
      prev->next = current->next;
    }
  free (current);
}

int main ()
{
  node *head = NULL;
  add_first (&head, 3);
  add_first (&head, 2);
  add_first (&head, 1);
  printf ("List after adding elements at beginning: ");
  print_list (head);
  printf ("\n");
  add_last (&head, 4);
  add_last (&head, 5);
  printf ("List after adding elements at end: ");
  print_list (head);
  printf ("\n");
  delete_node (&head, 3);
  printf ("List after deleting element in middle: ");
  print_list (head);
  printf ("\n");
  printf ("List using recursive function: ");
  print_list_recursive (head);
  printf ("\n");
  printf ("List using non-recursive function: ");
  print_list (head);
  printf ("\n");
  return 0;
}
