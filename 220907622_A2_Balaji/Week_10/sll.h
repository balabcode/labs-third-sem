#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll {
    int coeff;
    int expon;
    struct ll *next;
} node;

node *createNode() {
    node *temp = (node *) calloc(1, sizeof(node));
    temp->next = NULL;
    return temp;
}

int isEmpty(node **head) {
    return *head == NULL;
}

void insertFront(node **head, int exp, int co) {
    node *temp = createNode();
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void insertRear(node **head, int x) {
    node *temp = createNode();
    temp->data = x;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    temp->next = *head;
}


int deleteFront(node **head) {
    int element = (*head)->data;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return element;
}

int deleteRear(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    if ((*head)->next == NULL) {
        int element = (*head)->data;
        free(*head);
        *head = NULL;
        return element;
    }
    node *p = *head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    int element = p->next->data;
    free(p->next);
    p->next = NULL;
    return element;
}

void display(node **head) {
    node *p = *head;
    while (p != NULL) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}
