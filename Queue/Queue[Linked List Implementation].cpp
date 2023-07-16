#include<stdio.h>
#include<stdlib.h>
struct node *f=NULL;
struct node *r=NULL;

struct node
{
	int data;
	struct node *next;
};
void traversal(struct node *ptr)
{
	
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
void enqueue(int val)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
	{
		printf("queue is full");
	}
	else
	{
		n->data=val;
		n->next=NULL;
		if(f==NULL)
		{
			f=r=n;//case of single node
		}
		else
		{
			r->next=n;
			r=n;
		}
	}
}
int dequeue()
{
	int val=-1;
	struct node *ptr=f;
	if(f==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		f=f->next;
		val=ptr->data;
		free(ptr);
	}
	return val;
}
int main()
{
	traversal(f);
	//enqueue
	enqueue(45);
	enqueue(12);
	enqueue(34);
	traversal(f);	
	//dequeue
	printf("dequeueing element %d",dequeue());
}
