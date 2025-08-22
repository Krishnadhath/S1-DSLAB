#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};




int main(){
    struct Node* head = NULL;
    struct Node* first = malloc(sizeof(struct Node));
    first->data = 89;
    struct Node* second = malloc(sizeof(struct Node));
    first ->next= second;
    second->data = 90;
    
    second ->next = NULL;
    //printf("%d " , first->data);
    head = first;

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode ->data = 100;
    newNode ->next = head;
    head = newNode;




    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; 
    }
    printf("NULL");
    return 0;

}
