#define MAX_SIZE 100
typedef struct
{
  int top;
  char data[MAX_SIZE];
} stack;
void
init_stack (stack * s)
{
  s->top = -1;
}

int
is_empty (stack * s)
{
  return s->top == -1;
}

int
is_full (stack * s)
{
  return s->top == MAX_SIZE - 1;
}

void
push (stack * s, char c)
{
  if (is_full (s))
    {
      printf ("Stack overflow\n");
      exit (1);
    }
  s->top++;
  s->data[s->top] = c;
}

char
pop (stack * s)
{
  if (is_empty (s))
    {
      printf ("Stack underflow\n");
      exit (1);
    }
  char c = s->data[s->top];
  s->top--;
  return c;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystack.h"
int main ()
{
  char str[MAX_SIZE];
  stack s;
  init_stack (&s);
  printf ("Enter a string: ");
  scanf ("%s", str);
  int len = strlen (str);
  int mid = len / 2;
  int i;
  for (i = 0; i < mid; i++)
    {
      push (&s, str[i]);
    }
  if (len % 2 != 0)
    {
      i++;
    }
  while (str[i] != '\0')
    {
      if (pop (&s) != str[i])
	{
	  printf ("%s is not a palindrome\n", str);
	  return 0;
	}
      i++;
    }
  printf ("%s is a palindrome\n", str);
  return 0;
}
