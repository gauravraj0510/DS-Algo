#include<stdio.h>
#include<stdlib.h>
struct node *create(int);
void display(struct node *);
struct node *delete(struct node *);
struct node
{
    int data;
    struct node *next;
};

int main() 
{
    printf("Enter the number of nodes:\n");
    int n;
    scanf("%d",&n);
    struct node *REAR;
    REAR = create(n);
    display(REAR);
    REAR = delete(REAR);
    display(REAR);
    return 0;
}

struct node *create(int n)
{
    int i;
    struct node *REAR, *TEMP;
    REAR = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node 1:");
    scanf("%d",&(REAR->data));
    REAR->next = REAR;
    for(i=2; i<=n; i++)
    {
        TEMP = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d:",i);
        scanf("%d",&(TEMP->data));
        TEMP->next = REAR->next;
        REAR->next = TEMP;
        REAR = REAR->next;
    }
    return REAR;
}

void display(struct node *REAR)
{
    struct node *TEMP;
    TEMP = REAR->next;
    do
    {
        printf("%d\t",(TEMP->data));
        TEMP = TEMP->next;
    } while (TEMP != REAR->next);
    
}

struct node *delete(struct node *REAR)
{
    int key;
    printf("\nEnter data of node to be deleted: ");
    scanf("%d", &key);
    struct node *TEMP, *TARGET;
    TEMP = REAR;
    while(TEMP->next->data != key && TEMP->next != REAR)
    {
        TEMP = TEMP->next;
    }
    if(TEMP->next->data == key)
    {
        TARGET = TEMP->next;
        TEMP->next = TARGET->next;
        free(TARGET);
        if(TARGET == REAR)
        {
            REAR = TEMP;
        }
    }
    else
    {
        printf("\nElement not found!\n");
    }
    return REAR;
}