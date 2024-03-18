#include <stdio.h>
#include <stdlib.h>

// Structure for a node in BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to traverse BST in Inorder
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse BST in Preorder
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse BST in Postorder
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a key in BST
void searchKey(struct Node *root, int key) {
    if (root == NULL) {
        printf("Element %d not found in BST\n", key);
        return;
    }

    if (root->data == key) {
        printf("Element %d found in BST\n", key);
        return;
    }

    if (key < root->data)
        searchKey(root->left, key);
    else
        searchKey(root->right, key);
}

int main() {
    struct Node *root = NULL;
    int choice, key;

    // Create the BST with given elements
    int elements[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < numElements; i++) {
        root = insertNode(root, elements[i]);
    }

    do {
        printf("\n----- Menu -----\n");
        printf("1. Traverse BST in Inorder\n");
        printf("2. Traverse BST in Preorder\n");
        printf("3. Traverse BST in Postorder\n");
        printf("4. Search Element in BST\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchKey(root, key);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
