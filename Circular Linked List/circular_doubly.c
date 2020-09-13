#include <stdlib.h>
#include <stdio.h>
struct node *create(int);
void display(struct node *);
struct node
{
    int data;
    struct node *next, *prev;
};
int main()
{
    int n;
    struct node *HEAD;
    printf("Enter the no of node: ");
    scanf("%d", &n);
    HEAD = create(n);
    display(HEAD);
    return 0;
}
struct node *create(int n)
{
    struct node *HEAD, *P;
    int i;
    HEAD = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node 1: ");
    scanf("%d", &(HEAD->data));
    HEAD->next = HEAD;
    HEAD->prev = HEAD;
    P = HEAD;
    for (i = 2; i <= n; i++)
    {
        P->next = (struct node *)malloc(sizeof(struct node));
        P->next->prev = P;
        P = P->next;
        printf("Enter data for node %d: ", i);
        scanf("%d", &(P->data));
    }
    P->next = HEAD;
    HEAD->prev = P;
    return HEAD;
}
void display(struct node *HEAD)
{
    struct node *TEMP, *REV, *REAR;
    TEMP = HEAD;
    printf("\nOriginal Linked List: \n");
    do
    {
        printf("%d\t",TEMP->data);
        REV = TEMP;
        TEMP = TEMP->next;
    }
    while(TEMP != HEAD);
    REAR = REV;
    printf("\nReverse Linked List: \n");
    do
    {
        printf("%d\t",REV->data);
        REV = REV->prev;
    }
    while(REV != REAR);
}