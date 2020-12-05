#include <stdio.h>
void enqueue();
void dequeue();
void display();
int queue[100];
int MAX = 100;
int front = -1;
int rear = -1;
int main()
{
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
    int data;
    if(rear == MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        if(rear == -1){
            front = 0;
        }
        printf("Enter data to added in queue: ");
        scanf("%d", &data);
        printf("\n");
        rear = rear + 1;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Dequeued element is: %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Queue elements are: ");
        for( i = front; i <= rear; i++ )
            printf("%d\t", queue[i]);
        printf("\n");
    }
}