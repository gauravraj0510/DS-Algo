#include<stdio.h>
#include<stdlib.h>
struct node *create(int);
void display(struct node *);
struct node *concat(struct node *, struct node *);
struct node
{
    int data;
    struct node *next;
};

int main() {
    struct node *HEAD1, *HEAD2, *HEAD;
    int n1,n2;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n1);
    HEAD1 = create(n1);
    printf("Enter the number of nodes:\n");
    scanf("%d",&n2);
    HEAD2 = create(n2);
    HEAD = concat(HEAD1,HEAD2);
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

struct node *concat(struct node *HEAD1, struct node *HEAD2){
    if(HEAD2 == NULL)
        return HEAD1;
    if(HEAD1 == NULL)
        return HEAD2;
    
    struct node *TEMP;
    TEMP = HEAD1;
    while(TEMP->next != NULL){
        TEMP = TEMP->next;
    }
    TEMP->next = HEAD2;
    return HEAD1;
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
