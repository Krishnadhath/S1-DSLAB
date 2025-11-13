#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;


void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if(q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if(isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue
int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if(q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Graph structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// BFS function
void bfs(Node* adjList[], int start, int n) {
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while(!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        Node* temp = adjList[current];
        while(temp) {
            int adjVertex = temp->vertex;
            if(!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n = 6; // Number of vertices
    Node* adjList[n];

    // Initialize adjacency list
    for(int i = 0; i < n; i++)
        adjList[i] = NULL;

    // Example graph
    // Edge 0-1
    Node* newNode = createNode(1);
    newNode->next = adjList[0];
    adjList[0] = newNode;

    // Edge 0-2
    newNode = createNode(2);
    newNode->next = adjList[0];
    adjList[0] = newNode;

    // Edge 1-3
    newNode = createNode(3);
    newNode->next = adjList[1];
    adjList[1] = newNode;

    // Edge 1-4
    newNode = createNode(4);
    newNode->next = adjList[1];
    adjList[1] = newNode;

    // Edge 2-4
    newNode = createNode(4);
    newNode->next = adjList[2];
    adjList[2] = newNode;

    // Edge 3-5
    newNode = createNode(5);
    newNode->next = adjList[3];
    adjList[3] = newNode;

    // Perform BFS starting from vertex 0
    printf("BFS traversal starting from vertex 0: ");
    bfs(adjList, 0, n);

    return 0;
}
