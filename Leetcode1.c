#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch){
    top++;
    stack[top] = ch;
}

char pop(){
    return stack[top--];
}

int main()
{
    char word[100];
    char temp[100] = "";
    char remaining[100] = "";
    char ch;
    int index = -1;
    int i;

    printf("Enter the word: ");
    scanf("%s", word);

    printf("Enter the character: ");
    scanf(" %c", &ch);
    for(i = 0; word[i] != '\0'; i++){
        if(word[i] == ch)
        {
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Resulting string: %s", word);
        return 0;
    }
    for(i = 0; i <= index; i++){
        push(word[i]);
    }
    i = 0;
    while(top != -1){
        temp[i] = pop();
        i++;
    }
    temp[i] = '\0';
    strcpy(remaining, &word[index + 1]);
    strcat(temp, remaining);
    printf("Resulting string: %s", temp);

    return 0;
}
