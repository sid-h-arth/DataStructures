#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int data;
};
void traversal (struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("element: %d \n",ptr->data);
		ptr=ptr->next;
	}
}
struct node* end(struct node* head,int data)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->data=data;
	temp->next=ptr;
	ptr->next=NULL;
	return head;
	
}
int main()
{
	struct node *head;
	struct node *second;
	struct node *third;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	
	head->data=76;
	head->next=second;
	
	second->data=32;
	second->next=third;
	
	third->data=21;
	third->next=NULL;
	
	traversal(head);
	printf("after insertion: \n");
	
	end(head,99);
	traversal(head);
}
