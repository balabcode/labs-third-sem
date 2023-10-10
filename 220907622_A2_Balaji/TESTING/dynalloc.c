#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p = (int*)calloc(10,sizeof(int));
	p = (int*)realloc(p, 15*sizeof(int));
	printf("%ld",sizeof(p));
}