#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* head = NULL;

// display
void displayList(){
    Node* current = head;
    if(current == NULL){
        printf("Empty list \n");
        return;
    }
    printf("[ ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf(" ]\n");
}

// Insertion at beginning
void insertBegin(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(head == NULL){
        head = newNode;
    }
    else{
        head->prev = newNode;
        head = newNode;
    }
}

// Insertion at end
void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Insert after a given node
void insertAfterNode(Node* pre, int value){
    if(pre == NULL){
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    newNode->prev = pre;
    newNode->next = pre->next;

    if(pre->next != NULL){
        pre->next->prev = newNode;
    }

    pre->next = newNode;
}

// Delete from beginning
void deleteBegin(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

// Delete from end
void deleteEnd(){
    if(head == NULL) return;

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

// Delete node by value
void deleteNode(int value){
    if(head == NULL) return;

    // If head node has the value
    if(head->data == value){
        deleteBegin();
        return;
    }

    Node* current = head;
    while(current != NULL && current->data != value){
        current = current->next;
    }
    
    if(current == NULL){
        printf("Value %d not found\n", value);
        return;
    }

    // Node to be deleted is current
    if(current->next != NULL){
        current->next->prev = current->prev;
    }
    if(current->prev != NULL){
        current->prev->next = current->next;
    }
    
    free(current);
    printf("Deleted node with value %d\n", value);
}

int main(){
    printf("Doubly Linked List Demo\n");
    printf("========================\n\n");
    
    displayList();
    
    insertBegin(10);
    insertBegin(20);
    insertBegin(30);
    printf("After inserting at beginning: ");
    displayList();
    
    insertEnd(40);
    insertEnd(50);
    printf("After inserting at end: ");
    displayList();
    
    // Insert after head (after 30)
    printf("\nInserting 25 after head (30):\n");
    insertAfterNode(head, 25);
    displayList();
    
    // Insert after second node
    printf("Inserting 15 after second node (20):\n");
    insertAfterNode(head->next->next, 15);
    displayList();
    
    printf("\nDeleting from beginning:\n");
    deleteBegin();
    displayList();
    
    printf("Deleting from end:\n");
    deleteEnd();
    displayList();
    
    printf("\nDeleting node with value 20:\n");
    deleteNode(20);
    displayList();
    
    printf("Deleting node with value 10:\n");
    deleteNode(10);
    displayList();
    
    return 0;
}