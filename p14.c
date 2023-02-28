#include <stdio.h>
#define MAX_SIZE 100
void merge (double arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  double L[MAX_SIZE], R[MAX_SIZE];
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
	{
	  arr[k] = L[i];
	  i++;
	}
      else
	{
	  arr[k] = R[j];
	  j++;
	}
      k++;
    }
  while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }
  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

void mergesort (double arr[], int left, int right)
{
  if (left < right)
    {
      int mid = left + (right - left) / 2;
      mergesort (arr, left, mid);
      mergesort (arr, mid + 1, right);
      merge (arr, left, mid, right);
    }
}

int main ()
{
  double arr[] = { 9.5, 8.6, 7.7, 6.8, 5.9, 4.0, 3.1, 2.2, 1.3, 0.4 };
  int n = sizeof (arr) / sizeof (arr[0]);
  mergesort (arr, 0, n - 1);
  printf ("Sorted array: ");
  for (int i = 0; i < n; i++)
    printf ("%lf ", arr[i]);
  printf ("\n");
  return 0;
}
