#include<stdio.h>
#include<conio.h>
int evaluate(char, int, int);
void push(int);
int pop(void);

int stack[20];
int TOP = -1;

int main()
{
    int op1, op2, val;
    char x;
    printf("Enter your postfix epression: ");
    while((x = getchar()) != '\n')
    {
        if(isdigit(x))
            push(x-48);
        else
        {
            op2 = pop();
            op1 = pop();
            val = evaluate(x, op1, op2);
            push(val);
        }        
    }
    val = pop();
    printf("The answer is: %d", val);
    return 0;
}

int evaluate(char x, int op1, int op2)
{
    if(x == '+')
        return (op1+op2);
    else if(x == '-')
        return (op1-op2);
    else if(x == '*')
        return (op1*op2);
    else if(x == '/')
        return (op1/op2);
    else if(x == '%')
        return (op1%op2);
}

void push(int x)
{
    TOP = TOP + 1;
    stack[TOP] = x;
}

int pop()
{
    int x;
    x = stack[TOP];
    TOP--;
    return x;
}