#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void traversal(struct node *temp)
{
	
	while(temp!=NULL)
	{
		printf(" %d \t",temp->data);
		temp=temp->next;
	}
}
struct node* position(struct node *head,int data,int index)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node*p=head;
	newnode->data=data;
	int i=1;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	newnode->next=p->next;
	p->next=newnode;
	return head;
}
int main()
{
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	fourth=(struct node*)malloc(sizeof(struct node));
	
	head->data=54;
	head->next=second;
	
	second->data=76;
	second->next=third;
	
	third->data=876;
	third->next=fourth;
	
	fourth->data=32;
	fourth->next=NULL;
	
	traversal(head);
	printf("\n");
	position(head,99,3);
	traversal(head);	
}
