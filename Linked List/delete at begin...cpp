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
struct node* deleteatbegin(struct node* head)
{
	
	struct node* newnode=head;
	head=head->next;
	free(newnode);
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
head=	deleteatbegin(head);
	traversal(head);
}
