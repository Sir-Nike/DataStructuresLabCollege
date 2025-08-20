#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node* createNode(int d) {
    Node* n = malloc(sizeof(Node));
    if (!n) { printf("Memory error\n"); exit(1); }
    n->data = d; n->prev = n->next = NULL;
    return n;
}

void insertRear(int d) {
    Node* n = createNode(d);
    if (!head) head = tail = n;
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void deleteRear() {
    if (!tail) { printf("List empty\n"); return; }
    Node* temp = tail;
    printf("Deleted: %d\n", temp->data);
    if (head == tail) head = tail = NULL;
    else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void insertAtPosition(int d, int pos) {
    if (pos < 1) { printf("Invalid pos\n"); return; }
    Node* n = createNode(d);
    if (pos == 1) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
        return;
    }
    Node* t = head;
    for (int i=1; t && i < pos-1; i++) t = t->next;
    if (!t) { printf("Pos out of bounds\n"); free(n); return; }
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    else tail = n;
    t->next = n;
}

void deleteAtPosition(int pos) {
    if (!head || pos < 1) { printf("Invalid pos or empty\n"); return; }
    Node* t = head;
    if (pos == 1) {
        printf("Deleted: %d\n", t->data);
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        free(t);
        return;
    }
    for (int i=1; t && i < pos; i++) t = t->next;
    if (!t) { printf("Pos out of bounds\n"); return; }
    printf("Deleted: %d\n", t->data);
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    if (t == tail) tail = t->prev;
    free(t);
}

void insertAfterValue(int val, int d) {
    Node* t = head;
    while (t && t->data != val) t = t->next;
    if (!t) { printf("Value %d not found\n", val); return; }
    Node* n = createNode(d);
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    else tail = n;
    t->next = n;
}

void insertBeforeValue(int val, int d) {
    Node* t = head;
    while (t && t->data != val) t = t->next;
    if (!t) { printf("Value %d not found\n", val); return; }
    Node* n = createNode(d);
    n->next = t;
    n->prev = t->prev;
    if (t->prev) t->prev->next = n;
    else head = n;
    t->prev = n;
}

void traverseForward() {
    printf("List (forward): ");
    for (Node* t = head; t; t = t->next) printf("%d ", t->data);
    printf("\n");
}

void traverseBackward() {
    printf("List (reverse): ");
    for (Node* t = tail; t; t = t->prev) printf("%d ", t->data);
    printf("\n");
}

void freeList() {
    Node* t = head;
    while (t) {
        Node* nxt = t->next;
        free(t);
        t = nxt;
    }
    head = tail = NULL;
}

int main() {
    int choice, data, pos, val;
    while (1) {
        printf("\n1.Insert rear\n2.Delete rear\n3.Insert pos\n4.Delete pos\n5.Insert after val\n6.Insert before val\n7.Traverse fwd\n8.Traverse bwd\n9.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); printf("Invalid input\n"); continue; }
        switch(choice) {
            case 1: printf("Data: "); scanf("%d", &data); insertRear(data); break;
            case 2: deleteRear(); break;
            case 3: printf("Pos: "); scanf("%d", &pos); printf("Data: "); scanf("%d", &data); insertAtPosition(data, pos); break;
            case 4: printf("Pos: "); scanf("%d", &pos); deleteAtPosition(pos); break;
            case 5: printf("After value: "); scanf("%d", &val); printf("Data: "); scanf("%d", &data); insertAfterValue(val, data); break;
            case 6: printf("Before value: "); scanf("%d", &val); printf("Data: "); scanf("%d", &data); insertBeforeValue(val, data); break;
            case 7: traverseForward(); break;
            case 8: traverseBackward(); break;
            case 9: freeList(); printf("Exiting\n"); return 0;
            default: printf("Invalid choice\n");
        }
    }
}

