#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
  char name[50];
  int roll;
  int marks;
} Student;
typedef struct node
{
  Student data;
  struct node *prev;
  struct node *next;
} Node;
void add_first (Node ** head, Student data)
{
  Node *new_node = malloc (sizeof (Node));
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = *head;
  if (*head != NULL)
    {
      (*head)->prev = new_node;
    }
  *head = new_node;
}

void add_last (Node ** head, Student data)
{
  Node *new_node = malloc (sizeof (Node));
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;
  if (*head == NULL)
    {
      *head = new_node;
      return;
    }
  Node *last_node = *head;
  while (last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  last_node->next = new_node;
  new_node->prev = last_node;
}

void delete_node (Node ** head, Node * node)
{
  if (*head == NULL || node == NULL)
    {
      return;
    }
  if (*head == node)
    {
      *head = node->next;
    }
  if (node->next != NULL)
    {
      node->next->prev = node->prev;
    }
  if (node->prev != NULL)
    {
      node->prev->next = node->next;
    }
  free (node);
}

void print_list_forward (Node * head)
{
  Node *current = head;
  while (current != NULL)
    {
      printf ("Name: %s, Roll: %d, Marks: %d\n", current->data.name,
	      current->data.roll, current - >data.marks);
      current = current->next;
    }
}

void print_list_backward (Node * head)
{
  Node *current = head;
  while (current != NULL && current->next != NULL)
    {
      current = current->next;
    }
  while (current != NULL)
    {
      printf ("Name: %s, Roll: %d, Marks: %d\n", current->data.name,
	      current->data.roll, current - >data.marks);
      current = current->prev;
    }
}

int main ()
{
  Node *head = NULL;
  add_first (&head, (Student)
	     {
	     "John Doe", 1, 80});
  add_last (&head, (Student)
	    {
	    "Jane Smith", 2, 90});
  add_first (&head, (Student)
	     {
	     "Bob Johnson", 3, 85});
  printf ("List in forward order:\n");
  print_list_forward (head);
  printf ("\nList in backward order:\n");
  print_list_backward (head);
  Node *node_to_delete = head->next;
  delete_node (&head, node_to_delete);
  printf ("\nList after deleting node with roll number %d:\n",
	  node_to_delete->data.roll);
  print_list_forward (head);
  return 0;
}
