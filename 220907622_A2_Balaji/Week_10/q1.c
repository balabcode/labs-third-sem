#include "dll.h"
//Question: Write a menu driven program to implement doubly linked list without header node
//to insert into and delete from both the sides.

int main(){
	node* head = NULL;
	int op;
	int x;
	printf("Select 1 to insFront, 2 to insRear, 3 to delFront, 4 to delRear, 5 to display, 0 to exit\n");
	do{
		printf("Option: ");
		scanf("%d", &op);
		switch(op){
		case 1:
			printf("Number: ");
			scanf("%d", &x);
			insFront(&head, x);
			break;
		case 2:
			printf("Number: ");
			scanf("%d", &x);
			insRear(&head, x);
			break;
		case 3:
			printf("Dequeued: %d\n\n", delFront(&head));
			break;
		case 4:
			printf("Dequeued: %d\n\n", delRear(&head));
			break;
		case 5:
			display(&head);
			break;
		case 0:
			break;
		default:
			printf("Please enter a valid input!\n\n");
			break;
		}
	}while(op != 0);
}