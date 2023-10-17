#include "dll_string.h"

int main(){
	node* head = NULL;
	insRear(&head, "Hello!");
	insRear(&head, "World.");
	display(&head);
	reverse(&head);
	display(&head);
}

