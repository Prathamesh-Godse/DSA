#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a student
struct Student {
    char USN[20];
    char Name[50];
    char Programme[50];
    int Sem;
    long long PhNo;
    struct Student* next;
};

// Function prototypes
void insertFront(struct Student **head_ref);
void display(struct Student *head);
int countNodes(struct Student *head);
void insertEnd(struct Student **head_ref);
void deleteEnd(struct Student **head_ref);
void deleteFront(struct Student **head_ref);

int main() {
    struct Student *head = NULL;
    int choice;

    do {
        printf("\n***** MENU *****\n");
        printf("1. Insert at Front\n");
        printf("2. Display and Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Front\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertFront(&head);
                break;
            case 2:
                display(head);
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 3:
                insertEnd(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                deleteFront(&head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to insert a student at the front of the list
void insertFront(struct Student **head_ref) {
    struct Student *new_student = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter USN: ");
    scanf("%s", new_student->USN);
    printf("Enter Name: ");
    scanf("%s", new_student->Name);
    printf("Enter Programme: ");
    scanf("%s", new_student->Programme);
    printf("Enter Semester: ");
    scanf("%d", &new_student->Sem);
    printf("Enter Phone Number: ");
    scanf("%lld", &new_student->PhNo);

    new_student->next = *head_ref;
    *head_ref = new_student;
    printf("Student inserted at front successfully.\n");
}

// Function to display the list and count the number of nodes
void display(struct Student *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student *temp = head;
    printf("Student Data:\n");
    while(temp != NULL) {
        printf("USN: %s, Name: %s, Programme: %s, Semester: %d, Phone Number: %lld\n", temp->USN, temp->Name, temp->Programme, temp->Sem, temp->PhNo);
        temp = temp->next;
    }
}

// Function to count the number of nodes in the list
int countNodes(struct Student *head) {
    int count = 0;
    struct Student *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a student at the end of the list
void insertEnd(struct Student **head_ref) {
    struct Student *new_student = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter USN: ");
    scanf("%s", new_student->USN);
    printf("Enter Name: ");
    scanf("%s", new_student->Name);
    printf("Enter Programme: ");
    scanf("%s", new_student->Programme);
    printf("Enter Semester: ");
    scanf("%d", &new_student->Sem);
    printf("Enter Phone Number: ");
    scanf("%lld", &new_student->PhNo);

    new_student->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new_student;
    } else {
        struct Student *temp = *head_ref;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
    printf("Student inserted at end successfully.\n");
}

// Function to delete a student from the end of the list
void deleteEnd(struct Student **head_ref) {
    if(*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        printf("Student deleted from end successfully.\n");
        return;
    }

    struct Student *second_last = *head_ref;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
    printf("Student deleted from end successfully.\n");
}

// Function to delete a student from the front of the list
void deleteFront(struct Student **head_ref) {
    if(*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Student *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    printf("Student deleted from front successfully.\n");
}
