#include<stdlib.h>
#include<stdio.h>
struct node *create(int);
void insertMid(struct node *);
void display(struct node *);
struct node
{
    int data;
    struct node *next,*prev;
};
int main()
{
    int n;
    struct node *HEAD;
    printf("Enter the no of node: ");
    scanf("%d", &n);
    HEAD = create(n);
    display(HEAD);
    insertMid(HEAD);
    display(HEAD);
    return 0;
}
struct node *create(int n)
{
    struct node *HEAD, *P;
    int i;
    HEAD = (struct node *)malloc(sizeof(struct node));
    if(HEAD == NULL){
        printf("\nMemory cant be allocated");
    }
    else{
        printf("Enter data for node 1: ");
        scanf("%d",&(HEAD->data));
        HEAD->next = NULL;
        HEAD->prev = NULL;
        P = HEAD;
        for(i = 2; i <= n; i++)
        {
            P->next = (struct node *)malloc(sizeof(struct node));
            P->next->prev = P;
            P = P->next;
            printf("Enter data for node %d: ",i);
            scanf("%d", &(P->data));
        }
        P->next = NULL;        
    }
    return HEAD;
}
void insertMid(struct node *HEAD)
{
    struct node *TEMP, *P;
    int key;
    printf("\n\nEnter data of node after which new node needs to be inserted: ");
    scanf("%d",&key);
    TEMP = HEAD;
    while(key != TEMP->data && TEMP != NULL)
    {
        TEMP = TEMP->next;
    }   
    if(TEMP != NULL){
        P = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data for new node: ");
        scanf("%d",&(P->data));
        P->next = TEMP->next;
        P->prev = TEMP;
        TEMP->next->prev = P;
        TEMP->next = P;
    }
    else{
        printf("\nNode not found!");
    }
}
void display(struct node *HEAD)
{
    struct node *TEMP;
    TEMP = HEAD;
    printf("\nOriginal linked list:\n");
    while (TEMP != NULL)
    {
        printf("\t%d",TEMP->data);
        TEMP = TEMP->next;
    }
}