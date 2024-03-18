#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert(char element) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
        printf("Queue Overflow\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted: %c\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (i = front; i <= rear; i++)
            printf("%c ", queue[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%c ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%c ", queue[i]);
    }
    printf("\n");
}

int main() {
    char choice, element;
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter the element to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case '2':
                delete();
                break;
            case '3':
                display();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != '4');
    return 0;
}
