#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void traversal(struct node *temp)
{
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
struct node* insertatend(struct node *head,int data)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	struct node *temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=p;
	p->prev=temp1;
	p->next=NULL;
}
int main()
{
	struct node *head;
	struct node *n2;
	struct node *n3;
	struct node *n4;
	head=(struct node*)malloc(sizeof(struct node));
	n2=(struct node*)malloc(sizeof(struct node));
	n3=(struct node*)malloc(sizeof(struct node));
	n4=(struct node*)malloc(sizeof(struct node));
	
	head->data=45;
	head->prev=NULL;
	head->next=n2;
	
	n2->data=56;
	n2->prev=head;
	n2->next=n3;
	
	n3->data=78;
	n3->prev=n2;
	n3->next=n4;
	
	n4->data=83;
	n4->prev=n3;
	n4->next=NULL;
	
	traversal(head);
	printf("\n");
	insertatend(head,99);
	traversal(head);
	
}
