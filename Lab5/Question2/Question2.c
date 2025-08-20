#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data; n->prev = n->next = NULL;
    return n;
}

void append(Node** head, int data) {
    Node *newNode = createNode(data), *temp = *head;
    if (!*head) *head = newNode;
    else {
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

void concatenate(Node** X1, Node* X2) {
    if (!*X1) *X1 = X2;
    else if (X2) {
        Node* last = *X1;
        while (last->next) last = last->next;
        last->next = X2;
        X2->prev = last;
    }
}

int main() {
    Node *X1 = NULL, *X2 = NULL;
    for (int i = 1; i <= 3; i++) append(&X1, i);
    for (int i = 4; i <= 6; i++) append(&X2, i);

    printf("X1 before: "); printList(X1);
    printf("X2 before: "); printList(X2);

    concatenate(&X1, X2);

    printf("X1 after: "); printList(X1);
    return 0;
}


