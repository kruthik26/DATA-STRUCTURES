#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char value){
    top++;
    stack[top] = value;
}

char pop(){
    return stack[top--];
}

int priority(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    int brackets = 0;

    printf("ENTER THE INFIX EXPRESSION : ");
    scanf("%s", exp);

    e = exp;
    while(*e != '\0'){
        if(*e == '(')
            brackets++;

        else if(*e == ')'){
            brackets--;

            if(brackets < 0){
                printf("INVALID PARENTHESIS");
                return 0;
            }
        }

        e++;
    }

    if(brackets != 0){
        printf("INVALID PARENTHESIS");
        return 0;
    }
    e = exp;

    printf("POSTFIX EXPRESSION : ");

    while(*e != '\0'){
        if(isalnum(*e))
        {
            printf("%c", *e);
        }

        else if(*e == '(')
        {
            push(*e);
        }

        else if(*e == ')'){
            while((x = pop()) != '('){
                printf("%c", x);
            }
        }

        else{
            while(top != -1 &&priority(stack[top]) >= priority(*e)){
                printf("%c", pop());
            }

            push(*e);
        }

        e++;
    }

    while(top != -1){
        printf("%c", pop());
    }

    return 0;
}
