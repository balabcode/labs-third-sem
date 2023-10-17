#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct n{
    char* data;
    struct n* next;
    struct n* prev;
} node;

node* createNode(){
    node* temp = (node*)calloc(1,sizeof(node));
    temp->data = (char*)calloc(MAX, sizeof(char));
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

void insFront(node** head, char x[]){
    node* temp = createNode();
    temp->data = x;
    if (*head == NULL) {
        *head = temp;
    } else {
        temp->next = *head;
        temp->prev = (*head)->prev;
        (*head)->prev->next = temp;
        (*head)->prev = temp;
        *head = temp;
    }
}

void insRear(node** head, char x[]){
    node* temp = createNode();
    temp->data = x;
    if (*head == NULL) {
        *head = temp;
    } else {
        temp->prev = (*head)->prev;
        temp->next = *head;
        (*head)->prev->next = temp;
        (*head)->prev = temp;
    }
}

char* delFront(node** head){
    if (*head == NULL) {
        printf("Skill Issue: List is empty!\n\n");
        return "cringe: not in list";
    }
    char* x = (*head)->data;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return x;
}

char* delRear(node** head){
    if (*head == NULL) {
        printf("Skill Issue: List is empty!\n\n");
        return "cringe: not in list";
    }
    char* x = (*head)->prev->data;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        node* temp = (*head)->prev;
        (*head)->prev = temp->prev;
        temp->prev->next = *head;
        free(temp);
    }
    return x;
}

void display(node** head){
    if (*head == NULL) {
        printf("Skill Issue: List is empty!\n\n");
        return;
    }
    node* p;
    for(p = (*head); p->next != (*head); p = p->next){
        printf("%s  ", p->data);
    }
    printf("%s\n", p->data);
}

void reverse(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    node* current = *head;
    node* temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != *head);
    *head = temp->prev;
}
