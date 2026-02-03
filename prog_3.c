#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Normal traversal (forward)
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse traversal using recursion
void reverseTraversal(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    // Recurse to the end first
    reverseTraversal(head->next);
    
    // Then print while coming back
    printf("%d -> ", head->data);
}

// Display list in reverse
void displayReverse(struct Node* head) {
    reverseTraversal(head);
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    printf("Linked List - Reverse Traversal Demo\n");
    printf("=====================================\n\n");
    
    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> 50
    printf("Creating linked list...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("\nForward traversal:\n");
    traverse(head);
    
    printf("\nReverse traversal:\n");
    displayReverse(head);
    
    // Test with another list
    printf("\n\nCreating another list...\n");
    struct Node* head2 = NULL;
    insertAtBeginning(&head2, 5);
    insertAtBeginning(&head2, 4);
    insertAtBeginning(&head2, 3);
    insertAtBeginning(&head2, 2);
    insertAtBeginning(&head2, 1);
    
    printf("\nForward traversal:\n");
    traverse(head2);
    
    printf("\nReverse traversal:\n");
    displayReverse(head2);
    
    printf("\n");
    
    return 0;
}