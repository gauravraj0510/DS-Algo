#include <stdio.h>
#include <string.h>
void push(char);
char pop();

int TOP = -1;
char stack[20];

int main()
{
    char x;
    printf("\nEnter your expression: ");
    while((x = getchar()) != '\n')
    {
        if(x == '(')
            push('(');
        else if(x == ')')
        {
            if(TOP == -1){
                printf("\nLeft Parenthesis Missing!");
                return 0;
            }  
            pop();
        }
    }
    if(TOP != -1)
        printf("\nRight Parenthesis Missing!");
    else
        printf("\nBalanced Parenthesis!");
    return 0;
}

void push(char x)
{
    TOP = TOP + 1;
    stack[TOP] = x;
}

char pop()
{
    char x;
    x = stack[TOP];
    TOP--;
    return x;
}