#include "linkedlist.h"

node* intersection(node** h1, node** h1){
	node* h3 = NULL;
	node* p1 = *h1;
	node* p2 = *h2;
	for(int i = p1->data; p1->next!=NULL; p1 = p1->next){
		for(int j = p2->data; p2->next!=NULL; p2 = p2->next){
			if(i == j){
				insertRear(&h3,i);
			}
		}
	}
}

node* union(node** h1, node** h1){
	node* h3 = NULL;
	node* p1 = *h1;
	node* p2 = *h2;
	int items[100];
	for(int i = p1->data; p1->next!=NULL; p1 = p1->next){
		if()
		insertRear(&h3, i);
	}
	for

	// for(int i = p1->data; p1->next!=NULL; p1 = p1->next){
	// 	for(int j = p2->data; p2->next!=NULL; p2 = p2->next){
	// 		if(i == j){
	// 			insertRear(&h3,i);
	// 		}
	// 	}
	// }
}
