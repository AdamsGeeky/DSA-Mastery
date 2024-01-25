#include <stdio.h>
#include <stdlib.h> // for malloc

// Definition of the node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Functions prototype
Node* createNode(int newData);
void insertAtBeginning(Node** head, int newData);
void insertAtEnd(Node** head, int newData);
void insertAtPosition(Node** head, int newData, int position);
void printList(Node* head);
void sortList(Node* head);

// Main function
int main() {
    Node* head = NULL;
    int choice;
    int newData, position;

    printf("\t\t\t Doubly Linked List Operations:\n");

    while (1) {
        // Display menu
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Sort the doubly linked list\n");
        printf("5. Print the doubly linked list\n");
        printf("6. Exit\n");

        // Get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\t Enter data to insert at the beginning: ");
                scanf("%d", &newData);
                insertAtBeginning(&head, newData);
                break;

            case 2:
                printf("\t Enter data to insert at the end: ");
                scanf("%d", &newData);
                insertAtEnd(&head, newData);
                break;

            case 3:
                printf("\t Enter data to insert: ");
                scanf("%d", &newData);
                printf("\t Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, newData, position);
                break;

            case 4:
                // Sort the doubly linked list
                sortList(head);
                break;

            case 5:
                // Print the doubly linked list
                printList(head);
                break;

            case 6:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Operations

// Function to create a new node
Node* createNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(Node** head, int newData, int position) {
    Node* newNode = createNode(newData);
    if (position <= 0) {
        // Insert at the beginning
        insertAtBeginning(head, newData);
    } else {
        Node* current = *head;
        int currentPosition = 1;

        // Traverse to the desired position or the end of the list
        while (current != NULL && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        // Update pointers to insert the new node
        if (current != NULL) {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev = newNode;

            if (newNode->prev != NULL) {
                newNode->prev->next = newNode;
            } else {
                *head = newNode; // Update head if inserting at the beginning
            }
        } else {
            // Insert at the end if the position is beyond the length of the list
            insertAtEnd(head, newData);
        }
    }
}

// Function to print the doubly linked list in forward and reverse order
void printList(Node* head) {
    // Print in forward order
    printf("Forward: ");
    Node* tempForward = head; // Use a temporary pointer for forward print
    while (tempForward != NULL) {
        printf("%d -> ", tempForward->data);
        tempForward = tempForward->next;
    }
    printf("NULL\n");

    // Move to the end of the list using a separate pointer
    Node* tail = head;
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next;
    }

    // Print in reverse order
    printf("Reverse: ");
    while (tail != NULL) {
        printf("%d -> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

// Function to sort the doubly linked list
// Function to sort the doubly linked list in ascending order (using bubble sort)
void sortList(Node* head) {
    Node *current, *index;
    int temp;

    if (head == NULL) {
        printf("List is empty. Nothing to sort.\n");
        return;
    }

    printf("Before sorting: ");
    printList(head);

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                // Swap node's data
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("After sorting: ");
    printList(head);

    printf("Doubly linked list sorted in ascending order.\n");
}
