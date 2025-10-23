#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = n; // Points to itself initially
    return n;
}

void insertEnd(struct Node **head, int data) {
    struct Node *n = create(data);
    if (!*head) { *head = n; return; }
    struct Node *temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = n;
    n->next = *head;
}

void delete(struct Node **head, int key) {
    if (!*head) return;
    struct Node *curr = *head, *prev = NULL;

    // If head is the node to be deleted
    if (curr->data == key) {
        while (curr->next != *head) curr = curr->next;
        if (curr == *head) { // only one node
            free(*head);
            *head = NULL;
            return;
        }
        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    prev = *head;
    curr = (*head)->next;
    while (curr != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == *head) return; // not found
    prev->next = curr->next;
    free(curr);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
