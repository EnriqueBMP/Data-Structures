#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} CircularList;

CircularList* createList() {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(CircularList* list) {
    return list->size == 0;
}

int getSize(CircularList* list) {
    return list->size;
}

Node* getHead(CircularList* list) {
    return list->head;
}

Node* getTail(CircularList* list) {
    return list->tail;
}

void addFront(CircularList* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (isEmpty(list)) {
        node->next = node;
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->tail->next = node;
        list->head = node;
    }
    list->size++;
}

void addEnd(CircularList* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (isEmpty(list)) {
        node->next = node;
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void addAt(CircularList* list, int data, int pos) {
    if (pos <= 0) {
        addFront(list, data);
    } else if (pos >= list->size) {
        addEnd(list, data);
    } else {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;
        Node* temp = list->head;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;
        node->next = temp->next;
        temp->next = node;
        list->size++;
    }
}

void removeFront(CircularList* list) {
    if (isEmpty(list)) return;
    Node* temp = list->head;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }
    free(temp);
    list->size--;
}

void removeEnd(CircularList* list) {
    if (isEmpty(list)) return;
    Node* temp = list->tail;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        Node* current = list->head;
        while (current->next != list->tail) current = current->next;
        current->next = list->head;
        list->tail = current;
    }
    free(temp);
    list->size--;
}

void removeAt(CircularList* list, int pos) {
    if (isEmpty(list)) return;
    if (pos <= 0) {
        removeFront(list);
    } else if (pos >= list->size - 1) {
        removeEnd(list);
    } else {
        Node* current = list->head;
        for (int i = 0; i < pos - 1; i++) current = current->next;
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->size--;
    }
}

int search(CircularList* list, int data) {
    if (isEmpty(list)) return -1;
    Node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        if (temp->data == data) return i;
        temp = temp->next;
    }
    return -1;
}

void traverse(CircularList* list) {
    if (isEmpty(list)) return;
    Node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clear(CircularList* list) {
    while (!isEmpty(list)) removeFront(list);
}

void display(CircularList* list) {
    traverse(list);
}

int main() {
    CircularList* list = createList();
    int choice, data, pos;
    do {
        printf("\n1.Add Front\n2.Add End\n3.Add At\n4.Remove Front\n5.Remove End\n6.Remove At\n7.Search\n8.Traverse\n9.Size\n10.Is Empty\n11.Clear\n12.Display\n13.GetHead\n14.GetTail\n0.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Data: "); scanf("%d", &data);
                addFront(list, data);
                break;
            case 2:
                printf("Data: "); scanf("%d", &data);
                addEnd(list, data);
                break;
            case 3:
                printf("Data: "); scanf("%d", &data);
                printf("Position: "); scanf("%d", &pos);
                addAt(list, data, pos);
                break;
            case 4:
                removeFront(list);
                break;
            case 5:
                removeEnd(list);
                break;
            case 6:
                printf("Position: "); scanf("%d", &pos);
                removeAt(list, pos);
                break;
            case 7:
                printf("Data: "); scanf("%d", &data);
                pos = search(list, data);
                if (pos == -1) printf("Not found\n");
                else printf("Found at position %d\n", pos);
                break;
            case 8:
                traverse(list);
                break;
            case 9:
                printf("Size: %d\n", getSize(list));
                break;
            case 10:
                printf(isEmpty(list) ? "Empty\n" : "Not Empty\n");
                break;
            case 11:
                clear(list);
                break;
            case 12:
                display(list);
                break;
            case 13:
                if (getHead(list)) printf("Head: %d\n", getHead(list)->data);
                else printf("No Head\n");
                break;
            case 14:
                if (getTail(list)) printf("Tail: %d\n", getTail(list)->data);
                else printf("No Tail\n");
                break;
        }
    } while (choice != 0);
    clear(list);
    free(list);
    return 0;
}
