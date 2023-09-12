#define MAX 10 
#define true 1
#define false 0

/* Structure definition */ 
typedef struct
{
	int item[MAX]; 
	int top;
}stack;
void push(stack *ps,int x); 
void pop_print(stack *ps);
int pop(stack *ps);
int empty(stack *ps);

/* Push operation */
void push(stack *ps,int x)
{
	if (ps->top!=MAX-1)
	{
		ps->top++;
		ps->item[ps->top]=x;
	}
}
/* Pop operation */
void pop_print(stack *ps)
{
	if(!empty(ps)){
		// return(ps->item[ps->top--]);
		printf("%d\n", ps->item[ps->top--]);
	}
	else
		printf("Stack is empty!\n");
}
int pop(stack *ps){
	return(ps->item[ps->top--]);
}
/* Stack empty operation */
int empty(stack *ps)
{
	if (ps->top==-1)
		return(true);
	else
		return(false);
}
int full(stack *ps){
	if(ps->top == MAX-1)
		return (true);
	else
		return (false);
}

void display(stack *ps){
	for(int i = 0; i <= ps->top; i++){
		printf("%d  ", ps->item[i]);
	}
	printf("\n");
}