
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void create(struct Node **head) {
    struct Node *newnode, *temp;
    int n, i;

    *head = NULL;

    printf("ENTER THE NUMBER OF NODES: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (*head == NULL) {
            *head = newnode;
        }
        else {
            temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
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

    printf("Deleted node from beginning.\n");
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
        printf("Deleted node from end.\n");
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Deleted node from end.\n");
}


void deleteAtPosition(struct Node **head, int position) {
    struct Node *temp, *delNode;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        deleteFromFirst(head);
        return;
    }

    temp = *head;

    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    delNode = temp->next;
    temp->next = delNode->next;

    free(delNode);

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


int main() {
    struct Node *head = NULL;
    int choice, position;

    create(&head);

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromFirst(&head);
                break;

            case 2:
                deleteFromEnd(&head);
                break;

            case 3:
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");

                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }

                return 0;

            default:
                printf("Invalid choice! Select between 1 and 5.\n");
        }
    }

    return 0;
}
