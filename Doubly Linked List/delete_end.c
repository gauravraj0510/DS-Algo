#include<stdlib.h>
#include<stdio.h>
struct node *create(int);
void deleteEnd(struct node *);
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
    deleteEnd(HEAD);
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
void deleteEnd(struct node *HEAD)
{
    struct node *TEMP;
    if(HEAD->next == NULL){
        free(HEAD);
        HEAD = NULL;
    }
    else{
        TEMP = HEAD;
        while(TEMP->next->next != NULL){
            TEMP = TEMP->next;
        }
        free(TEMP->next);
        TEMP->next = NULL;
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