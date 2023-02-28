#include <stdio.h>
int add (int a, int b)
{
  return a + b;
}

int subtract (int a, int b)
{
  return a - b;
}

int main ()
{
  int a = 10, b = 5;
  int (*ptr) (int, int);
  ptr = add;
  printf ("Addition result: %d\n", ptr (a, b));
  ptr = subtract;
  printf ("Subtraction result: %d\n", ptr (a, b));
  return 0;
}
