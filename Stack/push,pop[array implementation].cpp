#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int top;
	int *arr;
};

int isfull(struct stack *ptr)
{
	if(ptr->top==ptr->size-1)
	{
		return 1;
	//	printf("stack is empty\n");
	}
	else
	{
		return 0;
	}
}
int isempty(struct stack *ptr)
{
	if(ptr->top==-1)
	{
		return 1;
	//	printf("stack is empty\n");
	}
	else
	{
		return 0;
	}
}
void push(struct stack *ptr,int val)
{
	if(isfull(ptr))
	{
		printf("stack overflow cannot push %d\n",val);
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top]=val;
		printf("%d\n",val);
	}
}
int pop(struct stack *ptr)
{
	if(isempty(ptr))
	{
		printf("underflow,stack is empty\n");
		return -1;
	}
	else
	{
		int val=ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}
int main()
{
	struct stack *sp=(struct stack*)malloc(sizeof(struct stack));//pointer to the sructure
	//allocates  memory for structure which stores stack,its size and top 
	sp->size=3;//max size of stack
	sp->top=-1;//points the location of control
	sp->arr=(int*)malloc(sp->size*sizeof(int));//dynamically allocates memory for the stack
	printf("stack created \n");
	//pushing element manually
//	sp->arr[0]=4;
//	sp->top++;
	//printf("stack full: %d\n",isfull(sp));
	//printf("stack empty: %d\n",isempty(sp));
	if(isempty(sp))
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("stack is not empty\n");
	}
	printf("before pushing stack full:%d\n",isfull(sp));
	printf("before pushing stack empty:%d\n",isempty(sp));
	printf("inserting elements in the stack:\n");
	push(sp,75);//pushing elements through push function
	push(sp,75);
	push(sp,67);//at this point stack becomes full rest comes under overflow
	push(sp,54);
	push(sp,79);
	printf("after pushing stack full:%d\n",isfull(sp));
	printf("after pushing stack empty:%d\n",isempty(sp));
	//popping the elements 
	printf("popped element is%d\n",pop(sp));
	printf("popped element is%d\n",pop(sp));
	push(sp,77);
	push(sp,1);
	push(sp,3);
	
//	push(sp,54);
	
	//printf("%d\n",isfull(sp));
	//printf("%d\n",isempty(sp));
}
