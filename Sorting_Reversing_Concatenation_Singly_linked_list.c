#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*next;
};
struct node*head=NULL;

void create(struct node **head)
{
    struct node *newnode, *temp;
    int choice = 1;

    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(*head == NULL)
        {
            *head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1)? ");
        scanf("%d", &choice);
    }
}

struct node *sort(struct node *head){
  struct node *temp,*current;
  int swap;

  if(head==NULL){
     printf("LIST IS EMPTY\n");
        return 0 ;
     }

  for(temp=head;temp->next!=NULL;temp=temp->next){
    for(current=temp->next;current!=NULL;current=current->next){
            if(temp->data>current->data){
                swap=temp->data;
                temp->data=current->data;
                current->data=swap;
            }
      }
  }
  return head;
}


struct node *reversing(struct node *head){
    struct node *current=head;
    struct node *prev=NULL;
    struct node *next;

    while(current!=NULL){
        next=current->next;
        current->next=prev;

        prev=current;
        current=next;
    }
    return prev;
}


struct node *concat(struct node *head1, struct node *head2){

    struct node *temp;

    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }

    temp=head1;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=head2;
    return head1;
}

void display(struct node *head){
  if(head==NULL){
    printf("LIST IS EMPTY\n");
    return ;
  }

  struct node *temp=head;

  while(temp!=NULL){
    printf("%d  ",temp->data);
    temp=temp->next;
  }
  printf("\n");
  return ;
}

int main(){
 struct node *head=NULL;
 struct node *head2=NULL;
 int choice;

 printf("SINGLY LINKED LIST OPERATIONS \n");
 printf("1.CREATE LINKED LIST \n");
 printf("2.SORT LINKED LIST \n");
 printf("3.REVERSE LINKED LIST\n");
 printf("4.CONCAT LINKED LIST\n");
 printf("5.DISPLAY LINKED LIST\n");
 printf("6.EXIT\n\n");

 do{
    printf("ENTER THE CHOICE :");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            create(&head);
            break;
        case 2:
            head=sort(head);
            break;

        case 3:
            head=reversing(head);
            break;
        case 4:
            create(&head2);
            head=concat(head,head2);
            break;
        case 5:
            display(head);
            break;
        case 6:
           return 0;
        default:
            printf("Invalid choice\n");
            break;
    }
    }while(choice!=6);
 return 0;
}


