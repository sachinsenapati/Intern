#include <stdio.h>
void swap (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition (int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
    {
      if (arr[j] < pivot)
	{
	  i++;
	  swap (&arr[i], &arr[j]);
	}
    }
  swap (&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort (int arr[], int low, int high)
{
  if (low < high)
    {
      int pivot_index = partition (arr, low, high);
      quicksort (arr, low, pivot_index - 1);
      quicksort (arr, pivot_index + 1, high);
    }
}

int main ()
{
  int arr[] = { 5, 2, 8, 1, 6, 9 };
  int n = sizeof (arr) / sizeof (arr[0]);
  printf ("Unsorted array: ");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
  quicksort (arr, 0, n - 1);
  printf ("Sorted array: ");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
  return 0;
}
