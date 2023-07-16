#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head;

void traversal(struct node *temp)
{
	
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
struct node* delatpos(struct node*head,int index)
{
	struct node*p,*q;
	int i=0;
	while(i<index)
	{
		p=p->next;
	}
	
	q=p->prev;
	q->next=p->next;
	p->prev=q;
	free(p);
	return head;
}

struct node* deleteatbegin(struct node *head)
{
	
	struct node*p;
	p=head;
	head=head->next;
	head->prev=NULL;
	free(p);
	return head;
	
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
	
	head->data=43;
	head->prev=NULL;
	head->next=n2;
	
	n2->data=32;
	n2->prev=head;
	n2->next=n3;
	
	n3->data=23;
	n3->prev=n2;
	n3->next=n4;
	
	n4->data=109;
	n4->prev=n3;
	n4->next=NULL;
	
	traversal(head);
	printf("\n");
	printf("after deletion\n");
//head=	deleteatbegin(head);
	traversal(head);
	head=delatpos(head,2);
}
