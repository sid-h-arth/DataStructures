#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void traversal(struct node* temp)
{
	while(temp!=NULL)
	{
		printf("element: %d \n",temp->data);
		temp=temp->next;
	}
}

struct node* insertatbegin(struct node*head,int data)
{

	struct node *p=(struct node*)malloc(sizeof(struct node));

	
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	head->prev=p;
	p->next=head;
    head=p;
}
int main()
{
	struct node*head;
	struct node*n2;
	struct node*n3;
	struct node*n4;
	head=(struct node*)malloc(sizeof(struct node));
	n2=(struct node*)malloc(sizeof(struct node));
	n3=(struct node*)malloc(sizeof(struct node));
	n4=(struct node*)malloc(sizeof(struct node));
	
	head->data=45;
	head->next=n2;
	head->prev=NULL;
	
	n2->data=23;
	n2->next=n3;
	n2->prev=head;
	
	n3->data=7;
	n3->next=n4;
	n3->prev=n2;
	
	n4->data=76;
	n4->next=NULL;
	n4->prev=n3;
	
	traversal(head);
  head=insertatbegin(head,999);
	traversal(head);
}
