#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5


typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void displayQueue(Queue *q);

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;
    
    printf("=== Queue Operations ===\n");
    printf("Queue size: %d elements\n\n", MAX_SIZE);
    
    while(1) {
        printf("\nMenu:\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(isFull(&q)) {
                    printf("Queue is full! Cannot enqueue.\n");
                } else {
                    printf("Enter element to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    printf("Element %d enqueued successfully.\n", value);
                }
                displayQueue(&q);
                break;
                
            case 2:
                if(isEmpty(&q)) {
                    printf("Queue is empty! Cannot dequeue.\n");
                } else {
                    value = dequeue(&q);
                    printf("Dequeued element: %d\n", value);
                }
                displayQueue(&q);
                break;
                
            case 3: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    
    return 0;
}

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(Queue *q) {
    return q->count == MAX_SIZE;
}


int isEmpty(Queue *q) {
    return q->count == 0;
}


void enqueue(Queue *q, int value) {
    if(isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX_SIZE; 
    q->items[q->rear] = value;
    q->count++;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE; 
    q->count--;
    return value;
}

void displayQueue(Queue *q) {
    printf("Current queue: ");
    
    if(isEmpty(q)) {
        printf("Empty\n");
        return;
    }
    
    int i = q->front;
    int elementsPrinted = 0;
    
    while(elementsPrinted < q->count) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        elementsPrinted++;
    }
    printf("\n");
    printf("Queue size: %d/%d elements\n", q->count, MAX_SIZE);
}
