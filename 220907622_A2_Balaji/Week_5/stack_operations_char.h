#define MAX 10 
#define true 1
#define false 0

/* Structure definition */ 
typedef struct
{
	char item[MAX]; 
	int top;
}stack;
void push(stack *ps,char x); 
void pop(stack *ps);
int empty(stack *ps);

/* Push operation */
void push(stack *ps,char x)
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
		printf("%c\n", ps->item[ps->top--]);
	}
	else
		printf("Stack is empty!\n");
}
char pop(stack *ps){
	if(!empty(ps)){
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
		printf("%c  ", ps->item[i]);
	}
	printf("\n");
}
void menu(stack *ps){
	int op;
	char letter;
	printf("Select 1 to pop, 2 to push, 3 to display, 0 to exit\n");
	do{
		printf("Option: ");
		scanf("%d", &op);
		switch(op){
		case 1:
			pop_print(ps);
			break;
		case 2:
			printf("Enter character to push: ");
			getchar();
			scanf("%c", &letter);
			push(ps, letter);
			break;
		case 3:
			display(ps);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Please enter a valid input!\n");
			break;
		}
	}while(op != 0);
}