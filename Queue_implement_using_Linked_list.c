#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newnode;
    newnode = malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("%d is deleted\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue elements are: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, ele;

    printf("QUEUE OPERATIONS USING LINKED LIST\n");

    printf("1. ENQUEUE TO QUEUE\n");
    printf("2. DEQUEUE TO QUEUE\n");
    printf("3. DISPLAY QUEUE\n");
    printf("4. EXIT\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element  to queue: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
