#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*next;//to link to the next node
	int data;//insert data values in nodes
};
// Case 1
struct node* insertAtFirst(struct node *head, int data){//creating new node
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;/*making the newly created node as 
	                as the head node*/
    ptr->next = head;
   // return ptr; 
}

void traversal(struct node *ptr)//for traversal in the list
{
	while(ptr!=NULL)
	{
		printf("element:  %d \n",ptr->data);
		ptr=ptr->next;//to print the data values in the nodes
	}
}
int main()
{
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	head=(struct node*)malloc(sizeof(struct node));//allocating the memory for nodes
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	fourth=(struct node*)malloc(sizeof(struct node));
	 
	 head->data=3;//giving data values and linking them to the next node
	 head->next=second;
	 
	 second->data=6;
	 second->next=third;
	 
	 third->data=9;
	 third->next=fourth;
	 
	 fourth->data=12;
	 fourth->next=NULL;
	 
	 traversal(head);//traversal starts from head before addition of new element
	head= insertAtFirst(head,75);//inserting new element
	traversal(head);	 //traversing after insertion
}
