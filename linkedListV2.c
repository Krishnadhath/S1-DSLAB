#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtHead(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node created with data: %d at head\n", data);
}


void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node created with data: %d at end\n", data);
}


void printList() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int num, data;
    printf("Enter number of nodes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter data for node: ");
        scanf("%d", &data);
        insertAtHead(data);  
    }

    insertEnd(9);  

    printList();

    

    return 0;
}
