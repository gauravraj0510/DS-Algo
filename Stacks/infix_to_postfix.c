#include<stdio.h>
#include<conio.h>
void converter(char[], char[]);
int precedence(char);
void push(char);
char pop(void);

int TOP;
char stack[30];

int main()
{
    char infix[30], postfix[30];
    printf("\nEnter the infix expression: ");
    gets(infix);
    converter(infix, postfix);
    printf("\nThe postfix expression is: %s\n", postfix);
    return 0;
}

void converter(char infix[30], char postfix[30])
{
    char x, token;
    int i, j=0;
    TOP = -1;
    for(i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if(isalnum(token))
            postfix[j++] = token;
        else if(token == '(')
            push('(');
        else if(token == ')')
            while((x = pop()) != '(')
                postfix[j++] = x;
        else
        {
            while(precedence(token) <= precedence(stack[TOP]) && TOP != -1)
            {
                x = pop();
                postfix[j++] = x;
            }
            push(token);
        }
    }
    while (TOP != -1)
    {
        x = pop();
        postfix[j++] = x;
    }
    postfix[j] = '\0';
}

int precedence(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    return 3;
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