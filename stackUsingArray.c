#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1; 


void push(int value){
    if(top == 9){
        printf("stack overflow\n");
    }else{
        top++;
        stack[top] = value;
        printf("pushed %d\n", value);
       }
    }

 void pop(){
    if(top == -1){
        printf("stack underflow\n");
    }
    else{
        printf("popped %d\n", stack[top]);
        top--;
    }
 }
 
 void display(){
    if(top == -1){
        printf("stack is empty \n");
    } else {
        printf("stack elements are: ");
        for(int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }
 }



 
int main() {
    
    push(89);
    push(20);
    push(34);
    push(45);
    display();
    pop();
    display();
    
    //printf("stack using array\n");
    
    return 0;
}