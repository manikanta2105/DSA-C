#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to push an element to the stack
void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to peek the top element of the stack
char peek(Stack *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[s->top];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;  // Highest precedence
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

// Function to check if a character is an operand (alphabet or digit)
int isOperand(char c) {
    return isalpha(c) || isdigit(c);  // Returns true if the character is a letter or a number
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;  // Index for the postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the result
        if (isOperand(c)) {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(&s, c);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (c == ')') {
            while (peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Pop '('
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                // Pop the operator from the stack to the postfix expression
                postfix[k++] = pop(&s);
            }
            push(&s, c);  // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators in the stack
    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character if present
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
