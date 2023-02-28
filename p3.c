/*
A pointer to pointer, also known as a double pointer, is a pointer variable that stores the memory 
address of another pointer variable. In other words, it is a pointer that points to another pointer.*/
#include <stdio.h>
int main ()
{
  int num = 42;
  int *ptr1 = &num;		// pointer to an integer variable
  int **ptr2 = &ptr1;		// pointer to a pointer variable
  printf ("Value of num = %d\n", num);
  printf ("Value of ptr1 = %p\n", ptr1);
  printf ("Value of ptr2 = %p\n", ptr2);

  printf ("Value of num using ptr1 = %d\n", *ptr1);
  printf ("Value of num using ptr2 = %d\n", **ptr2);

  return 0;
}
