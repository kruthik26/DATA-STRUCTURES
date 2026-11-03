
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Inserted %d at the beginning.\n", value);
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Inserted %d at the end.\n", value);
}

void insertMiddle(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
}

void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, position;


    while (1) {
        printf("\n=========================================\n");
        printf("       SINGLY LINKED LIST MENU           \n");
        printf("=========================================\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position (1-based)\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);


                insertBeginning(&head, value);
                break;

            case 2:
                 printf("Enter value to insert: ");
                 scanf("%d", &value);
                 insertEnd(&head, value);
                 break;

            case 3:
                 printf("Enter value to insert: ");
                 scanf("%d", &value);
                 printf("Enter position (1-based): ");
                 scanf("%d", &position);
                 insertMiddle(&head, value, position);
                 break;


            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Select between 1 and 5.\n");
        }
    }
    return 0;
}
