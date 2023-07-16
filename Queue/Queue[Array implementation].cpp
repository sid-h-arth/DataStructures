#include<stdio.h>
#include<stdlib.h>
struct  queue
{
	int size;
	int f;
	int r;
	int *arr;
};
int isEmpty(struct queue *q)
{
	if(q->r==q->f)
	{
	//	printf("queue underflow\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(struct queue *q)
{
	if(q->r==q->size-1)
	{
	//	printf("queue overflow\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(struct queue *q,int val)//inserts element at last
{
	if(isFull(q))
	{
		printf("queue is full,overflow\n");
	}
	else
	{
		q->r++;
		q->arr[q->r]=val;
		printf("%d\n",val);
	}
}
int dequeue(struct queue *q)//removes the first element
{
	if(isEmpty(q))
	{
		printf("queue underflow, queue is empty\n");
	}
	else
	{
		int a=-1;
		q->f++;
	    a=q->arr[q->f];
	    return a;
	}
}
int main()
{
	struct queue q;
	q.size=100;
	q.r=q.f=-1;//front and rear pointers
	q.arr=(int*)malloc(q.size*sizeof(int));//memory allocation for array
	printf("queue is full: %d\n",isFull(&q));
	printf("queue is empty: %d\n",isEmpty(&q));
	//enqueueing
	enqueue(&q,45);
	enqueue(&q,33);
	//dequeuing
	printf("dequeueing element: %d",dequeue(&q));
	printf("dequeueing element: %d",dequeue(&q));

	printf("queue is full: %d\n",isFull(&q));
	printf("queue is empty: %d\n",isEmpty(&q));
}
