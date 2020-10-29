#include <stdio.h>
#include <stdlib.h>
void push();
int pop();
void display();
struct stack
{
    int data;
    struct stack *next;
};

struct stack *TOP = NULL;
int size = 0;
int MAX = 5;

int main()
{
    int choice, data;
    while (1)
    {
        printf("\nSelect your choice:\n1)Push\n2)Pop\n3)Size\n4)Display\n5)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            if (!TOP)
            {
                printf("Empty Stack!!\n");
            }
            else
            {
                data = pop();
                printf("The popped data is %d\n", data);
            }
            break;

        case 3:
            printf("The size of stack is %d\n", size);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Wrong input! Try Again!!\n");
            break;
        }
    }
    return 0;
}

void push()
{
    if (size == MAX)
    {
        printf("The Stack is full!!\n");
    }
    else
    {
        struct stack *newNode = malloc(sizeof(struct stack));
        int data;
        printf("Enter data for new node:");
        scanf("%d", &(data));
        newNode->data = data;
        newNode->next = TOP;
        TOP = newNode;
        size++;
    }
}

int pop()
{
    struct stack *topNode;
    topNode = TOP;
    int data = topNode->data;
    TOP = TOP->next;
    free(topNode);
    size--;
    return data;
}

void display()
{
    printf("\n");
    struct stack *newTop;
    newTop = TOP;
    if (size > 0)
    {
        while (newTop != NULL)
        {
            printf("%d\t", newTop->data);
            newTop = newTop->next;
        }
    }
    else
    {
        printf("\nEmpty Stack!!");
    }
    printf("\n");
}