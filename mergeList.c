#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){

    int num = 0;
    int list1 = 0;
    printf("number of elements you need in first node");
    scanf("%d",&num);
    for(int i = 0; i< num; i++){
        
        printf("enter elements for the first list");
        scanf("%d",&list1);
        
    }
    return 0;
}