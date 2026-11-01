
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

void deleteFromFirst(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = *head;
    *head = temp->next;

    free(temp);

    printf("Deleted node from the beginning.\n");
}

void deleteFromEnd(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Deleted node from the end.\n");
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Deleted node from the end.\n");
}

void deleteAtPosition(struct Node **head, int position) {
    struct Node *temp, *nextNode;
    int i;

    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 0) {
        deleteFromFirst(head);
        return;
    }

    temp = *head;

    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    nextNode = temp->next;
    temp->next = nextNode->next;

    free(nextNode);

    printf("Deleted node at position %d.\n", position);
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

void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position (0-based)\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeList(&head);
                    return 0;
                }
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeList(&head);
                    return 0;
                }
                insertEnd(&head, value);
                break;

            case 3:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeList(&head);
                    return 0;
                }

                printf("Enter position (1-based): ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeList(&head);
                    return 0;
                }

                insertMiddle(&head, value, position);
                break;

            case 4:
                deleteFromFirst(&head);
                break;

            case 5:
                deleteFromEnd(&head);
                break;

            case 6:
                printf("Enter position (0-based index): ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeList(&head);
                    return 0;
                }

                deleteAtPosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                freeList(&head);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Select between 1 and 8.\n");
        }
    }

    freeList(&head);
    return 0;
}
