#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Simple stack for characters
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if(top == -1) return -1;
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// Check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get precedence of operators
int precedence(char c) {
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char c;
    
    for(i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        
        // If operand, add to output
        if(isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if(c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if(c == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else if(isOperator(c)) {
            while(!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    
    // Pop remaining operators
    while(!isEmpty()) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1;
    int i, val1, val2;
    
    for(i = 0; postfix[i] != '\0'; i++) {
        // If digit, push to stack
        if(isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        }
        // If operator, pop two elements and calculate
        else {
            val2 = stack[top--];
            val1 = stack[top--];
            
            switch(postfix[i]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
    }
    
    return stack[top];
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Infix to Postfix Converter\n");
    printf("==========================\n\n");
    
    // Test case 1
    strcpy(infix, "A+B*C");
    infixToPostfix(infix, postfix);
    printf("Infix:    %s\n", infix);
    printf("Postfix:  %s\n\n", postfix);
    
    // Test case 2
    strcpy(infix, "(A+B)*C");
    infixToPostfix(infix, postfix);
    printf("Infix:    %s\n", infix);
    printf("Postfix:  %s\n\n", postfix);
    
    // Test case 3 - with evaluation
    strcpy(infix, "2+3*4");
    infixToPostfix(infix, postfix);
    printf("Infix:    %s\n", infix);
    printf("Postfix:  %s\n", postfix);
    printf("Result:   %d\n\n", evaluatePostfix(postfix));
    
    // Test case 4
    strcpy(infix, "(2+3)*4");
    infixToPostfix(infix, postfix);
    printf("Infix:    %s\n", infix);
    printf("Postfix:  %s\n", postfix);
    printf("Result:   %d\n\n", evaluatePostfix(postfix));
    
    return 0;
}