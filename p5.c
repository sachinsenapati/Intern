#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
struct Stack
{
  int arr[MAX_SIZE];
  int top;
};
void
push (struct Stack *s, int data)
{
  if (s->top == MAX_SIZE - 1)
    {
      printf ("Error: Stack overflow\n");
      return;
    }
  s->arr[++(s->top)] = data;
  printf ("%d pushed to stack\n", data);
}

int pop (struct Stack *s)
{
  if (s->top == -1)
    {
      printf ("Error: Stack underflow\n");
      return -1;
    }
  int data = s->arr[s->top--];
  return data;
}

int peep (struct Stack *s)
{
  if (s->top == -1)
    {
      printf ("Error: Stack is empty\n");
      return -1;
    }
  return s->arr[s->top];
}

int IsEmpty (struct Stack *s)
{
  return s->top == -1;
}

int IsFull (struct Stack *s)
{
  return s->top == MAX_SIZE - 1;
}

int main ()
{
  struct Stack s;
  s.top = -1;
  int choice, data;
  while (1)
    {
      printf
	("\n1. Push\n2. Pop\n3. Peep\n4. IsEmpty\n5. IsFull\n6. Quit\nEnter your choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter data to push: ");
	  scanf ("%d", &data);
	  push (&s, data);
	  break;
	case 2:
	  data = pop (&s);
	  if (data != -1)
	    {
	      printf ("%d popped from stack\n", data);
	    }
	  break;
	case 3:
	  data = peep (&s);
	  if (data != -1)
	    {
	      printf ("%d is at the top of stack\n", data);
	    }
	  break;
	case 4:
	  if (IsEmpty (&s))
	    {
	      printf ("Stack is empty\n");
	    }
	  else
	    {
	      printf ("Stack is not empty\n");
	    }
	  break;
	case 5:
	  if (IsFull (&s))
	    {
	      printf ("Stack is full\n");
	    }
	  else
	    {
	      printf ("Stack is not full\n");
	    }
	  break;
	case 6:
	  exit (0);
	default:
	  printf ("Invalid choice\n");
	}
    }
  return 0;
}
