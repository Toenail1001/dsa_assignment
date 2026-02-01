#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push element onto stack
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

// Peek at top element
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Check if character is opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check if character is closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Check if brackets match
bool isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}'));
}

// Main function to check if expression has balanced parentheses
bool checkBalanced(char *expression) {
    Stack s;
    initStack(&s);
    
    int len = strlen(expression);
    
    for (int i = 0; i < len; i++) {
        char current = expression[i];
        
        // If opening bracket, push to stack
        if (isOpeningBracket(current)) {
            push(&s, current);
        }
        // If closing bracket, check with top of stack
        else if (isClosingBracket(current)) {
            if (isEmpty(&s)) {
                return false;  // No matching opening bracket
            }
            
            char top = pop(&s);
            if (!isMatchingPair(top, current)) {
                return false;  // Mismatched brackets
            }
        }
    }
    
    // If stack is empty, all brackets are balanced
    return isEmpty(&s);
}

int main() {
    // Test expressions
    char *expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);
    
    printf("Checking for balanced parentheses:\n");
    printf("=====================================\n\n");
    
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        
        if (checkBalanced(expressions[i])) {
            printf("Result: BALANCED\n");
        } else {
            printf("Result: NOT BALANCED\n");
        }
        printf("\n");
    }
    
    // Interactive mode
    printf("=====================================\n");
    printf("Enter your own expression (or 'quit' to exit):\n");
    
    char input[MAX_SIZE];
    while (1) {
        printf("\nExpression: ");
        if (fgets(input, MAX_SIZE, stdin) == NULL) {
            break;
        }
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        if (strlen(input) == 0) {
            continue;
        }
        
        if (checkBalanced(input)) {
            printf("Result: BALANCED\n");
        } else {
            printf("Result: NOT BALANCED\n");
        }
    }
    
    printf("\nThank you for using the program!\n");
    
    return 0;
}
