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
// Case 2: Deleting the element at a given index from the linked list
struct node * deleteAtIndex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
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
	deleteAtIndex(head,2);
	traversal(head);
	
}
