#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};



struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Changed head
        free(temp); // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp; // Return the node if found
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if not found
}
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    return prev; // New head of the reversed list
}
struct Node* deletefrombeginning(struct Node* head) {
    if (head == NULL) {
        return NULL; // List is empty
    }
    struct Node* temp = head;
    head = head->next; // Move head to the next node
    free(temp); // Free old head
    return head;
}
int main() {
    struct Node* head = NULL;

    
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Linked List: ");
    printList(head);

    // Search for a node
    int key = 20;
    struct Node* foundNode = searchNode(head, key);
    if (foundNode) {
        printf("Node with data %d found.\n", foundNode->data);
    } else {
        printf("Node with data %d not found.\n", key);
    }

    // Delete a node
    head = deleteNode(head, 20);
    printf("After deleting 20: ");
    printList(head);

    // Reverse the linked list
    head = reverseList(head);
    printf("Reversed Linked List: ");
    printList(head);

    // Delete from beginning
    head = deletefrombeginning(head);
    printf("After deleting from beginning: ");
    printList(head);

    return 0;
}
