#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

// a. Create Node
Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

// b. Display Nodes
void displayNodes(Node* head) {
	printf("List: ");
	Node* temp = head;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// c. Insert Node at beginning
Node* insertAtBeginning(Node* head, int value) {
	Node* newNode = createNode(value);
	newNode->next = head;
	return newNode;
}

// d. Insert Node at specific position (1-based)
Node* insertAtPosition(Node* head, int value, int pos) {
	if (pos <= 1 || !head) {
		return insertAtBeginning(head, value);
	}
	Node* temp = head;
	int i;
	for (i = 1; i < pos - 1 && temp->next; i++) {
		temp = temp->next;
	}
	Node* newNode = createNode(value);
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

// e. Insert Node at end
Node* insertAtEnd(Node* head, int value) {
	Node* newNode = createNode(value);
	if (!head) return newNode;
	Node* temp = head;
	while (temp->next) temp = temp->next;
	temp->next = newNode;
	return head;
}

// f. Delete Node at beginning
Node* deleteAtBeginning(Node* head) {
	if (!head) return NULL;
	Node* temp = head;
	head = head->next;
	free(temp);
	return head;
}

// g. Delete Node at end
Node* deleteAtEnd(Node* head) {
	if (!head) return NULL;
	if (!head->next) {
		free(head);
		return NULL;
	}
	Node* temp = head;
	while (temp->next->next) temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return head;
}

// h. Delete Node at position (1-based)
Node* deleteAtPosition(Node* head, int pos) {
	if (!head || pos <= 1) return deleteAtBeginning(head);
	Node* temp = head;
	int i;
	for (i = 1; i < pos - 1 && temp->next; i++) {
		temp = temp->next;
	}
	if (!temp->next) return head;
	Node* toDelete = temp->next;
	temp->next = toDelete->next;
	free(toDelete);
	return head;
}

int main() {
	Node* head = NULL;
	int choice, value, pos;
	while (1) {
		printf("\nMenu:\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert at position\n");
		printf("4. Delete at beginning\n");
		printf("5. Delete at end\n");
		printf("6. Delete at position\n");
		printf("7. Display list\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insertAtBeginning(head, value);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &value);
				head = insertAtEnd(head, value);
				break;
			case 3:
				printf("Enter value: ");
				scanf("%d", &value);
				printf("Enter position: ");
				scanf("%d", &pos);
				head = insertAtPosition(head, value, pos);
				break;
			case 4:
				head = deleteAtBeginning(head);
				break;
			case 5:
				head = deleteAtEnd(head);
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d", &pos);
				head = deleteAtPosition(head, pos);
				break;
			case 7:
				displayNodes(head);
				break;
			case 0:
				// Free all nodes before exit
				while (head) head = deleteAtBeginning(head);
				return 0;
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}
