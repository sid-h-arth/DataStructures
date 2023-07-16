/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
void traversal(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
}
struct node* insertbegin(struct node *head,int val)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=val;
    p->prev=NULL;
    p->next=head;
    head->prev=p;
    head=p;
    return p;
}
struct node* insertatindex(struct node *head,int val,int index)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head,*q;
    int i=1;
    p->data=val;
    p->next=NULL;
    p->prev=NULL;
    while(i<index)
    {
        temp=temp->next;
        i++;
    }
    q=temp->prev;
    q->next=p;
    p->prev=q;
    p->next=temp;
    temp->prev=p;
    return p;
}
struct node* insertatend(struct node *head,int val)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head;
    p->data=val;
    p->next=NULL;
    p->prev=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
    p->next=NULL;
    return p;
}
struct node* delatbegin(struct node *head)
{
    struct node *p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}
struct node* delatindex(struct node*head,int index)
{
    struct node *p=head;
    int i=1;
    while(i<index)
    {
        p=p->next;
        i++;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return head;
}
struct node* delatend(struct node*head)
{
    struct node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->prev->next=NULL;
    free(p);
    return head;
}

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *n2=(struct node*)malloc(sizeof(struct node));
    struct node *n3=(struct node*)malloc(sizeof(struct node));

    head->data=22;
    head->prev=NULL;
    head->next=n2;
    
    n2->data=75;
    n2->prev=head;
    n2->next=n3;
    
    n3->data=95;
    n3->prev=n2;
    n3->next=NULL;
    
    traversal(head);
    printf("\n");
    //head=insertbegin(head,9);
    //insertatindex(head,99,2);
    //insertatend(head,12);
    //head=delatbegin(head);
    //head=delatindex(head,2);
    //head=delatend(head);
    traversal(head);
    
    
    return 0;
}
