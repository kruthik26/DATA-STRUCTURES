#include<stdio.h>
#define MAX 5
int front=-1;
int rear=-1;
int queue[MAX];

void enqueue(int data){
  if(rear==MAX-1){
    printf("QUEUE IS FULL\n");
    return;
    }

 if(front==-1){
   front=0;
}
   rear++;
   queue[rear]=data;
}

int dequeue(){
  if ((front==-1)|| (front>rear) ){
     printf("QUEUE IS EMPTY\n");
     return -1;
  }
   int data=queue[front];
   front++;
   return data;
}

void display(){
  if(front==-1){
     printf("QUEUE IS EMPTY\n");
      return ;
  }
  printf("QUEUE ELEMENTS ARE ");
  for(int i=front;i<=rear;i++){
    printf("%d ",queue[i]);
  }
  printf("\n");
}

int main(){
  int choice,element;

  while(1==1){
  printf("ENTER 1 FOR ENQUEUE\n");
  printf("ENTER 2 FOR DEQUEUE\n");
  printf("ENTER 3 FOR DIAPLAY\n");
  printf("ENTER 4 FOR EXIT\n");
  printf("\n");

  printf("ENTER A CHOICE :");
  scanf("%d",&choice);

  switch(choice){
    case 1:
     printf("ENTER A ELEMENT TO ADD :");
     scanf("%d",&element);

     enqueue(element);
     break;

     case 2:
     element=dequeue();

     if(element!=-1){
     printf("DELETED ELEMENT :%d\n",element);
     }
     break;

     case 3:
     display();
     break;

     case 4:
     printf("YOU HAVE EXITED");
     return 0;
     break;

     default:
     printf("INVALID CHOICE");
     break;
     }
  }
}
