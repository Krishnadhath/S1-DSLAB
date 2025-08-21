#include <stdio.h>
#include <stdlib.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == 9){
    printf("queue full");
    }
    if(front == -1){
        front=0;
        rear++;
        queue[rear]=value;
        printf("queued %d",value);
    }

    else{
        rear++;
        queue[rear]=value;
        printf("queued %d",value);

    }
  }   
    
 
    void dequeue()
    {
        if (front==-1 || front>rear){
            printf("queue is empty");
        }
        
        printf("Dequed %d", queue[front]);
        front++;
    }
    void display(){
        

    }




int main(){
    enqueue(29);
    enqueue(20);
    dequeue();

}