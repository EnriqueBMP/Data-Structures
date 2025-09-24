#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = -1, count = 0;

void enqueue(int element){
    if (count == SIZE){
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    count++;
    printf("Element %d enqueued.\n", element);
}

void dequeue(){
    if (count == 0) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    int removed = queue[front];
    front = (front + 1) % SIZE;
    count--;
    printf("Dequeued element: %d\n", removed);
}

void displayQueue(){
    if (count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = 0; i < count; i++) {
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main(){
    int choice, element;

    do{
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                displayQueue();
                break;

            case 2:
                dequeue();
                displayQueue();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }while (choice != 3);

    return 0;
}
