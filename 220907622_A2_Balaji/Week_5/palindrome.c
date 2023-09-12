#include <stdio.h>
#include <stdlib.h>
#include "stack_operations_char.h"

void main(){
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top = -1;
	
	char str[100];
	printf("Enter a string: \n");
	// getchar();
	fgets(str,100,stdin);
	int n; 
	for(n = 0; str[n] != '\0'; n++);
	printf("%d\n",n);
	
	

}