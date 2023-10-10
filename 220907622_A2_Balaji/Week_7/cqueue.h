#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
	char x[MAX][100];
	int front;
	int rear;
}queue;

int isEmpty(queue *q){
	return (q->front == -1 && q->rear == -1);
}

int isFull(queue *q){
	return ((q->rear+1)%MAX == q->front);
}

void insert(queue *q, char s[]){
	if(isFull(q)){
		printf("The queue is full!\n");
	}
	else{
		if(isEmpty(q)){
			q->front = 0;
		}
		q->rear = (q->rear+1)%MAX;
		strcpy(q->x[q->rear], s);
	}
	
}

char* del(queue *q){
	char* str = (char*)calloc(MAX, sizeof(char));
	if(isEmpty(q)){
		strcpy(str, "mt");
		return "mt";
		// printf("mt\n");
	}
	else if(q->front == q->rear){
		strcpy(str, q->x[q->front]);
		q->front = -1;
		q->rear = -1;
		return str;
	}
	else{
		strcpy(str, q->x[q->front]);
		q->front = (q->front+1)%MAX;
		return str;
	}
	free(str);
}

void display(queue *q){
	if (isEmpty(q)){
		printf("The queue is empty!\n");
		return;
	}
	else{
		for(int i = q->front; i != ((q->rear+1)%MAX); i = (i+1)%MAX){
			puts(q->x[i]);
		}
	}
}

void menu(queue *q){
	int op;
	char letter;
	printf("Select 1 to delete, 2 to insert, 3 to display, 0 to exit\n");
	do{
		printf("Option: ");
		scanf("%d", &op);
		switch(op){
		case 1:
			puts(del(q));
			break;
		case 2:
			printf("Enter string to push: ");
			getchar();
			char str[100];
			fgets(str,100,stdin);
			insert(q, str);
			break;
		case 3:
			display(q);
			break;
		case 0:
			break;
		default:
			printf("Please enter a valid input!\n");
			break;
		}
	}while(op != 0);
}