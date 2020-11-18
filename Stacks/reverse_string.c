#include <stdio.h>
#include <string.h>
void push(char);
char pop();

char stack[50], string[50];
int TOP = -1;
int MAX = 50;

int main()
{
    int i;
    printf("Enter a string: ");
    gets(string);
    for(i = 0; i < strlen(string); i++)
    {
        push(string[i]);
    }
    for(i = 0; i < strlen(string); i++)
    {
        string[i] = pop();
    }
    printf("\nThe reversed string is: %s", string);
    return 0;
}

void push(char item)
{
    if(TOP == MAX-1)
    {
        printf("\nMax limit of string length has crossed!");
        return;
    }
    TOP = TOP + 1;
    stack[TOP] = item;
}

char pop()
{
    char item;
    if(TOP == -1)
    {
        printf("\nStack is empty!");
        return 0;
    }
    item = stack[TOP];
    TOP = TOP - 1;
    return item;
}


