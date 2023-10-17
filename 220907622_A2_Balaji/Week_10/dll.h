#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n{
	int data;
	struct n* next;
	struct n* prev;
}node;

node* createNode(){
	node* temp = (node*)calloc(1,sizeof(node));
	temp -> next = NULL;
	temp -> prev = NULL;
	return temp;
}

int isEmpty(node** head){
	return (((*head)) == NULL);
}

void insFront(node** head, int x){
	node* temp = createNode();
	temp->data = x;
	if(isEmpty(head)){
		(*head) = temp;
	}
	else{
		// node* p = (*head);
		(*head)->prev = temp;
		temp->next = (*head);
		(*head) = temp;
	}
}

void insRear(node *(*head), int x){
	node* temp = createNode();
	temp->data = x;
	if(isEmpty(head)){
		(*head) = temp;
	}
	else{
		node* p;
		for(p = (*head); p->next != NULL; p = p->next);
		p->next = temp;
		temp->prev = p;
	}
}

int delFront(node** head){
	if(isEmpty(head)){
		printf("Skill Issue: List is empty!\n\n");
		return -9999;
	}
	if((*head)->next == NULL){ 			//single element
		int x = (*head)->data;
		free(*head); 
		(*head) = NULL;
		return x;
	}
	int x = (*head)->data;
	(*head) = (*head)->next;
	free((*head)->prev);
	return x;
}

int delRear(node** head){
	if(isEmpty(head)){
		printf("Skill Issue: List is empty!\n\n");
		return -9999;
	}
	if((*head) -> next == NULL){  //single element
		int x = (*head)->data;
		free(*head); 
		(*head) = NULL;
		return x;
	}
	node* p;
	for(p = (*head); p->next != NULL; p = p->next);
	int x = p->data;
	p = p->prev;
	free(p->next);
	p->next = NULL;
	return x;
}

void display(node** head){
	if(isEmpty(head)){
		printf("Skill Issue: List is empty!\n\n");
		return;
	}
	node* p;
	for(p = (*head); p->next != NULL; p = p->next){
		printf("%d  ", p->data);
	}
	printf("%d\n", p->data);
}
