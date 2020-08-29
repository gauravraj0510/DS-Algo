#include<stdio.h>
#include<stdlib.h>
struct node *create(int);
void insertMid(struct node *);
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
    insertMid(HEAD);
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

void insertMid(struct node *HEAD){
    struct node *TEMP,*P;
    int key;
    P = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &(P->data));
    printf("Enter key data for insertion :");
    scanf("%d",&key);
    TEMP = HEAD;
    while (TEMP != NULL && key != (TEMP->data)){
        TEMP = TEMP->next;
    }
    if(TEMP != NULL){
        P->next = TEMP->next;
        TEMP->next = P;
    }   
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
