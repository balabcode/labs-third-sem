#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_operations_char.h"

void reverse (char *exp)
{

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
    	if(exp[i] == '(')
    		temp[j] = ')';
    	else if(exp[i] == ')')
    		temp[j] = '(';
    	else
    		temp[j] = exp[i];
      	
      	j--;
      	i++;
    }
  strcpy (exp, temp);
}
int precedence (char ch)
{
  	switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
  case '(':
  	return 4;
    }
  	return -1;
}

void convert(stack *ps, char exp[]){
	reverse(exp);
	for(int i = 0; exp[i]!='0'; i++){
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '(' || exp[i] == ')')
			while(!empty(ps)){
				if (precedence(exp[i]) > precedence(ps->item[ps->top]))
					push(ps, exp[i]);
				else if(exp[i] == ')'){
					while(ps->item[ps->top] != '('){
						pop_print(ps);
					}
					pop(ps);
				}
				else if(precedence(exp[i]) <= precedence(ps->item[ps->top])){
					pop_print(ps);
				}
			}
			// push(ps,exp[i]);
		else{
			printf("%c ", exp[i]);
		}
	}
	reverse(exp);
	puts(exp);	
}

void main(){
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top=-1;
	char exp[1000];
	printf("Expression: ");
	fgets(exp,1000,stdin);
	// printf("Answer: %.1f\n", eval(ps,exp));
	printf("Prefix: ");
	convert(ps,exp);
}