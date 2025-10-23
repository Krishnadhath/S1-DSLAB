#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(struct Node **head, int data) {
    struct Node *n = create(data), *temp = *head;
    if (!*head) { *head = n; return; }
    while (temp->next) temp = temp->next;
    temp->next = n; n->prev = temp;
}

void delete(struct Node **head, int key) {
    struct Node *t = *head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else *head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void display(struct Node *head) {
    for (; head; head = head->next) printf("%d ", head->data);
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);
    delete(&head, 20);
    display(head);
    return 0;
}
