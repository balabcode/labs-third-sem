#include <stdio.h>
#include <stdlib.h>
// Given two polynomials, write a program to perform the following operations on
// singly circular linked list with header node. Use menu driven approach to input two
// polynomials, subtract, multiply and display the result.
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

typedef struct Node* Poly;

Poly createPoly() {
    Poly head = (Poly)malloc(sizeof(struct Node));
    head->coeff = 0;
    head->exp = -1;
    head->next = head;
    return head;
}

void insertTerm(Poly head, int coeff, int exp) {
    Poly temp = (Poly)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = head->next;
    head->next = temp;
    head->coeff++;
}

void displayPoly(Poly head) {
    Poly temp = head->next;
    while (temp != head) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    }
    printf("\n");
}

Poly addPoly(Poly p1, Poly p2) {
    Poly res = createPoly();
    Poly t1 = p1->next;
    Poly t2 = p2->next;
    while (t1 != p1 && t2 != p2) {
        if (t1->exp == t2->exp) {
            insertTerm(res, t1->coeff + t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            insertTerm(res, t1->coeff, t1->exp);
            t1 = t1->next;
        } else {
            insertTerm(res, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    while (t1 != p1) {
        insertTerm(res, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != p2) {
        insertTerm(res, t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return res;
}

Poly subtractPoly(Poly p1, Poly p2) {
    Poly res = createPoly();
    Poly t1 = p1->next;
    Poly t2 = p2->next;
    while (t1 != p1 && t2 != p2) {
        if (t1->exp == t2->exp) {
            insertTerm(res, t1->coeff - t2->coeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            insertTerm(res, t1->coeff, t1->exp);
            t1 = t1->next;
        } else {
            insertTerm(res, -t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }
    while (t1 != p1) {
        insertTerm(res, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2 != p2) {
        insertTerm(res, -t2->coeff, t2->exp);
        t2 = t2->next;
    }
    return res;
}

Poly multiplyPoly(Poly p1, Poly p2) {
    Poly res = createPoly();
    Poly t1 = p1->next;
    while (t1 != p1) {
        Poly t2 = p2->next;
        while (t2 != p2) {
            int coeff = t1->coeff * t2->coeff;
            int exp = t1->exp + t2->exp;
            Poly temp = res->next;
            Poly prev = res;
            while (temp != res && temp->exp > exp) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != res && temp->exp == exp) {
                temp->coeff += coeff;
            } else {
                Poly newTerm = (Poly)malloc(sizeof(struct Node));
                newTerm->coeff = coeff;
                newTerm->exp = exp;
                newTerm->next = temp;
                prev->next = newTerm;
                res->coeff++;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return res;
}

int main() {
    Poly p1 = createPoly();
    Poly p2 = createPoly();
    int n1, n2, coeff, exp, choice;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the terms of polynomial 1 (coeff exp): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(p1, coeff, exp);
    }
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the terms of polynomial 2 (coeff exp): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(p2, coeff, exp);
    }
    do {
        printf("\nMenu:\n");
        printf("1. Add polynomials\n");
        printf("2. Subtract polynomials\n");
        printf("3. Multiply polynomials\n");
        printf("4. Display polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Result: ");
                displayPoly(addPoly(p1, p2));
                break;
            case 2:
                printf("Result: ");
                displayPoly(subtractPoly(p1, p2));
                break;
            case 3:
                printf("Result: ");
                displayPoly(multiplyPoly(p1, p2));
                break;
            case 4:
                printf("Polynomial 1: ");
                displayPoly(p1);
                printf("Polynomial 2: ");
                displayPoly(p2);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}
