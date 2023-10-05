#include <stdio.h>
#include <stdlib.h>
#include "stack_operations_int.h"

void main(){
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top = -1;
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	while(num > 0){
		push(ps,num%2);
		num = num/2;
	}

	for(int i = ps->top; i >= 0; i--){
		printf("%d  ", ps->item[i]);
	}
	printf("\n");
}