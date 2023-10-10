#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"

int main(){
	queue* q = (queue*)calloc(1,sizeof(queue));
	q->front = -1; q->rear = -1;
	menu(q);
	return 0;
}