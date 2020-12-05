#include <stdio.h>
#include <conio.h>
void enqueue();
void dequeue();
void display();
struct node{
    int data;
    struct node *next;
}; 
struct node *front, *rear;

int main()
{
    front = rear = NULL;
    int option;
    printf("Enter operation to be performed:\n");
    printf("1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Display\n");
    while (1)
    {
        scanf("%d", &option);
        switch (option)
        {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: display();
            break;
        case 4: exit(1);
            break;        
        default: printf("\nEnter correct option!\n");
            break;
        }
    }
    return 0;
}

void enqueue()
{
    struct node *temp;
    if(rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &(rear->data));
        rear->next = NULL;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &(temp->data));
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if(temp == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("\nDeleted Value is %d\n", temp->data);
        temp = temp->next;
        free(front);
        front = temp;
        if(front == NULL)
            rear = NULL;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if(temp == NULL)
    {
        printf("Underflow\n");
        return;
    }
    printf("\nQueue elements are:\n");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

