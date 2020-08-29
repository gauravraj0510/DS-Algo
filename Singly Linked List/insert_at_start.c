#include<stdio.h>
#include<stdlib.h>
struct node *create(int);
struct node *insertStart(struct node *);
void display(struct node *);
struct node
{
    int data;
    struct node *next;
};

int main() {
    printf("Enter the number of nodes:\n");
    int n;
    scanf("%d",&n);
    struct node *HEAD;
    HEAD = create(n);
    HEAD = insertStart(HEAD);
    display(HEAD);
    return 0;
}

struct node *create(int n) {
    struct node *HEAD, *P;
    int i;
    HEAD = (struct node *)malloc(sizeof(struct node));
    if(HEAD == NULL){
        printf("Memory not available!\n");
    }
    else{
        printf("Enter data for node 1:");
        scanf("%d",&(HEAD->data));
        HEAD->next = NULL;
        P = HEAD;

        for(i=2; i <= n; i++){
            P->next = (struct node *)malloc(sizeof(struct node));
            if(P->next == NULL){
                printf("Memory not available!\n");
                break;
            }
            else{
                P = P->next;
                printf("Enter data for node %d:", i);
                scanf("%d",&(P->data));    
            }
            P->next = NULL;
        }
    }
    return HEAD;
}

void display(struct node *HEAD){
    struct node *P;
    P = HEAD;
    printf("Data stored in linked list are:\n");
    while (P != NULL)
    {
        printf("\t %d",(P->data));
        P = P->next;
    }
}

struct node *insertStart(struct node *HEAD){
    struct node *P;
    P = (struct node *)malloc(sizeof(struct node));
    if(P == NULL){
        printf("Memory cannot be allocated");
    }
    else{
        printf("Enter data for new node:");
        scanf("%d",&(P->data));
        P->next = HEAD;
        HEAD = P;
    }
    return HEAD;
}
