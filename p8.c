#include <stdio.h>
#define MAX_SIZE 100
typedef struct
{
  int data[MAX_SIZE];
  int front;
  int rear;
} queue;
void init_queue (queue * q)
{
  q->front = 0;
  q->rear = 0;
}

int is_empty (queue * q)
{
  return q->front == q->rear;
}

int is_full (queue * q)
{
  return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue (queue * q, int element)
{
  if (is_full (q))
    {
      printf ("Queue overflow\n");
      return;
    }
  q->data[q->rear] = element;
  q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue (queue * q)
{
  if (is_empty (q))
    {
      printf ("Queue underflow\n");
      return -1;
    }
  int element = q->data[q->front];
  q->front = (q->front + 1) % MAX_SIZE;
  return element;
}

int count (queue * q)
{
  return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

int main ()
{
  queue q;
  init_queue (&q);
  int option, element;
  do
    {
      printf
	("Enter option (1 = enqueue, 2 = dequeue, 3 = count, 4 = exit): ");
      scanf ("%d", &option);
      switch (option)
	{
	case 1:
	  printf ("Enter element to enqueue: ");
	  scanf ("%d", &element);
	  enqueue (&q, element);
	  break;
	case 2:
	  element = dequeue (&q);
	  if (element != -1)
	    {
	      printf ("Dequeued element: %d\n", element);
	    }
	  break;
	case 3:
	  printf ("Number of elements in queue: %d\n", count (&q));
	  break;
	case 4:
	  printf ("Exiting program\n");
	  break;
	default:
	  printf ("Invalid option\n");
	  break;
	}
    }
  while (option != 4);
  return 0;
}
