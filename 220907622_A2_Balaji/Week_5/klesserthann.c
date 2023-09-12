#include <stdio.h>
#include <stdlib.h>
#include "stack_operations_int.h"

void main(){
	int n;
	int k;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int num[n];
	printf("Enter k: ");
	scanf("%d", &k);
	printf("Enter elements: \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top = -1;

	for(int i = 0; i < n; i++){
		while(!empty(ps) && k!=0){
			if(ps->item[ps->top] < num[i]){
				pop(ps);
				k--;
			}
			else
				break;
		}
		push(ps,num[i]);
	}
	display(ps);
}