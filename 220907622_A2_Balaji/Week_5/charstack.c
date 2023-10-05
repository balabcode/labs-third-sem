#include <stdio.h>
#include <stdlib.h>
#include "stack_operations_char.h"

void main(){
	stack *ps = (stack*)calloc(1,sizeof(stack));
	ps->top = -1;
	menu(ps);
}