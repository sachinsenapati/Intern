*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
  char name[50];
  int roll;
  float marks;
};
void
readStudentData (struct student *s)
{
  printf ("Enter name: ");
  scanf ("%s", s->name);
  printf ("Enter roll number: ");
  scanf ("%d", &s->roll);
  printf ("Enter marks: ");
  scanf ("%f", &s->marks);
}

void
printStudentData (const struct student *s)
{
  printf ("Name: %s\n", s->name);
  printf ("Roll number: %d\n", s->roll);
  printf ("Marks: %.2f\n", s->marks);
}

int main ()
{
  int n;
  printf ("Enter number of students: ");
  scanf ("%d", &n);
  struct student *students =
    (struct student *) malloc (n * sizeof (struct student));
  for (int i = 0; i < n; i++)
    {
      printf ("\nEnter details of student %d:\n", i + 1);
      readStudentData (&students[i]);
    }
  printf ("\nStudent details:\n");
  for (int i = 0; i < n; i++)
    {
      printf ("\nStudent %d:\n", i + 1);
      printStudentData (&students[i]);
    }
  free (students);
  return 0;
}
