#include<stdio.h>
#include<stdlib.h>
struct node//stack
{
	int data;
	struct node *next;	
} *top=NULL;
void traversal(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("element:%d\n",ptr->data);
		ptr=ptr->next;
	}
}
int isempty(struct node *ptr)
{
	if(ptr==NULL)
	{
		printf("underflow,stack is empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
int isfull(struct node *ptr)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("overflow,stack is full\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
struct node *push(struct node *top,int x)
{
	if(isfull(top))
	{
		printf("overflow\n");
	}
	else
	{
		struct node *n=(struct node*)malloc(sizeof(struct node));
		n->data=x;
		n->next=top;
		top=n;
		return top;	
	}
}
int pop(struct node **top)
{
	if(isempty(*top))
	{
		printf("underflow,stack is empty\n");
	}
	else
	{
		struct node *n=*top;
		*top=(*top)->next;
		int x=n->data;
		free(n);
		return x;	
	}
}
int main()
{
	struct node *top=NULL;
	top=push(top,87);
	top=push(top,52);
	top=push(top,99);
	traversal(top);
	printf("popped element is:%d\n",pop(&top));
	printf("updated stack:\n");
	traversal(top);
	return 0;
}
