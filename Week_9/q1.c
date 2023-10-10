#include "linkedlist.h"

int main(){
	node* head = NULL;
	int op;
	int x;
	printf("Select 1 to enqueue, 2 to dequeue, 3 to display, 0 to exit\n");
	do{
		printf("Option: ");
		scanf("%d", &op);
		switch(op){
		case 1:
			printf("Number: ");
			scanf("%d", &x);
			insertRear(&head, x);
			break;
		case 2:
			printf("Dequeued: %d\n", deleteFront(&head));
			break;
		case 3:
			display(&head);
			break;
		case 0:
			break;
		default:
			printf("Please enter a valid input!\n");
			break;
		}
	}while(op != 0);
	return 0;
}