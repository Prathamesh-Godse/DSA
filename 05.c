#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

// Structure of Stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push element into stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

// Function to pop element from stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to evaluate expression
int evaluateExpression(char exp[]) {
    struct Stack s;
    initialize(&s);
    int i, op1, op2, result;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
                case '%':
                    push(&s, op1 % op2);
                    break;
                case '^':
                    push(&s, (int)pow(op1, op2));
                    break;
                default:
                    printf("Invalid Operator\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    result = pop(&s);
    return result;
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Evaluate postfix expression\n");
    printf("2. Solve Tower of Hanoi problem\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        char exp[MAX_SIZE];
        printf("Enter the postfix expression: ");
        scanf("%s", exp);
        int result = evaluateExpression(exp);
        printf("Result: %d\n", result);
    } else if (choice == 2) {
        int n;
        printf("Enter number of disks for Tower of Hanoi: ");
        scanf("%d", &n);
        printf("The sequence of moves involved in the Tower of Hanoi are:\n");
        towerOfHanoi(n, 'A', 'C', 'B');
    } else {
        printf("Invalid choice. Please choose either 1 or 2.\n");
    }

    return 0;
}
