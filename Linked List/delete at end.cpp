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
		printf("element: %d \n",temp->data);
		temp=temp->next;
	}
}
struct node* deleteatend(struct node* head)
{
	struct node*p=head;
	struct node*q=head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
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
	 deleteatend(head);
	 traversal(head);
}
