#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int choice;
int TOP =-1;
int stack[MAX];

void push(int data){

  if(TOP==MAX-1){
    printf("STACK IS OVERFLOW\n");
  }
   TOP++;
   stack[TOP]=data;
}

int pop(){
    int value;
    if(TOP==-1){
    printf("STACK IS UNDERFLOW\n");

    }
    value=stack[TOP];
    TOP--;
    return stack[TOP+1];
}

void display(){
   printf("ELEMENTS IN THE STACK ARE ");
   for(int i=TOP;i>=0;i--){
    printf("%d\n",stack[i]);
   }
}

int main(){

    while (1==1){
    printf("\nSTACK MENU DRIVEN OPERATIONS\n");
    printf("ENTER 1 for PUSH element to stack\n");
    printf("ENTER 2 for POP element from the stack\n");
    printf("ENTER 3 for DISPLAY element from the stack\n");
    printf("ENTER 4 for exit\n");

    printf("ENTER A CHOICE ");
    scanf("%d",&choice);

    int value;
    int data;

    switch(choice){
    case 1:

        printf("ENTER ELEMENT TO ADD INTO THE STACK \n");
        scanf("%d",&data);

        push(data);
        break;

    case 2:
        value=pop();
        printf("POPED VALUE %d\n",value);
        break;

    case 3:
        display();
        break;
    case 4:
        printf("EXITED");
        exit(1);
    }
    }
    return 0;
}
