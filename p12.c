#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;
Node *
create_node (int data)
{
  Node *new_node = malloc (sizeof (Node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void
insert_recursive (Node ** root, int data)
{
  if (*root == NULL)
    {
      *root = create_node (data);
      return;
    }
  if (data < (*root)->data)
    {
      insert_recursive (&((*root)->left), data);
    }
  else if (data > (*root)->data)
    {
      insert_recursive (&((*root)->right), data);
    }
}

void
insert_iterative (Node ** root, int data)
{
  Node *new_node = create_node (data);
  if (*root == NULL)
    {
      *root = new_node;
      return;
    }
  Node *current = *root;
  Node *parent = NULL;
  while (current != NULL)
    {
      parent = current;
      if (data < current->data)
	{
	  current = current->left;
	}
      else if (data > current->data)
	{
	  current = current->right;
	}
      else
	{
	  return;		// Key already exists, no need to insert
	}
    }
  if (data < parent->data)
    {
      parent->left = new_node;
    }
  else
    {
      parent->right = new_node;
    }
}

void
inorder_traversal (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  inorder_traversal (root->left);
  printf ("%d ", root->data);
  inorder_traversal (root->right);
}

void
preorder_traversal (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  printf ("%d ", root->data);
  preorder_traversal (root->left);
  preorder_traversal (root->right);
}

void
postorder_traversal (Node * root)
{
  if (root == NULL)
    {
      return;
    }
  postorder_traversal (root->left);
  postorder_traversal (root->right);
  printf ("%d ", root->data);
}

int
main ()
{
  Node *root = NULL;
  insert_recursive (&root, 50);
  insert_recursive (&root, 30);
  insert_recursive (&root, 20);
  insert_recursive (&root, 40);
  insert_recursive (&root, 70);
  insert_recursive (&root, 60);
  insert_recursive (&root, 80);
  printf ("Inorder traversal: ");
  inorder_traversal (root);
  printf ("\n");
  printf ("Preorder traversal: ");
  preorder_traversal (root);
  printf ("\n");
  printf ("Postorder traversal: ");
  postorder_traversal (root);
  printf ("\n");
  insert_iterative (&root, 55);
  printf ("\nAfter inserting 55:\n");
  printf ("Inorder traversal: ");
  inorder_traversal (root);
  printf ("\n");
  printf ("Preorder traversal: ");
  preorder_traversal (root);
  printf ("\n");
  printf ("Postorder traversal: ");
  postorder_traversal (root);
  printf ("\n");
  return 0;
}
