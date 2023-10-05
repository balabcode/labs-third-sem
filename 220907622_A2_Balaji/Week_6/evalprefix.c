#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_operations_int.h"

double eval(stack *ps, char exp[]){
	double a, b;
	for(int j = strlen(exp) - 1; j >=0; j--){
		if(isdigit(exp[j]))
			push(ps,exp[j] - '0');
		else{
			a = ps->item[ps->top];
			pop(ps);
			b = ps->item[ps->top];
			pop(ps);
			switch(exp[j]){
			case '+':
				push(ps,a+b);
				break;
			case '-':
				push(ps, a-b);
				break;
			case '*':
				push(ps,a*b);
				break;
			case '/':
				push(ps, a/b);
				break;
			}
		}
	}
	return ps->item[ps->top];
}
void main(){
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top=-1;
	char exp[1000];
	printf("Expression: ");
	fgets(exp,1000,stdin);
	printf("Answer: %.1f\n", eval(ps,exp));
}