#include <stdio.h>
#include <stdlib.h>
struct node *create(int);
void display(struct node *);
struct node *add(struct node *, struct node *);
struct node *multiply(struct node *, struct node *);
struct node
{
    float coeff;
    int pow;
    struct node *next;
};
int main()
{
    int n1, n2;
    printf("\nEnter the no of terms in 1st polynomial: ");
    scanf("%d", &n1);
    struct node *HEAD1, *HEAD2, *HEAD, *T1, *T2, *TEMP;
    HEAD1 = create(n1);
    display(HEAD1);
    printf("\nEnter the no of terms in 2nd polynomial: ");
    scanf("%d", &n2);
    HEAD2 = create(n2);
    display(HEAD2);
    T1 = HEAD1;
    T2 = HEAD2;
    HEAD = NULL;
    while(T1 != NULL)
    {
        TEMP = multiply(T1,T2);
        HEAD = add(HEAD,TEMP);
        T1 = T1->next;
    }
    printf("\n\nAfter Multiplication:-");
    display(HEAD);
    return 0;
}
struct node *create(int n)
{
    struct node *HEAD, *P;
    int i;
    HEAD = (struct node *)malloc(sizeof(struct node));
    if (HEAD == NULL)
    {
        printf("Memory not available!\n");
    }
    else
    {
        printf("Enter power and co-eficient for term 1:");
        scanf("%d%f", &(HEAD->pow), &(HEAD->coeff));
        HEAD->next = NULL;
        P = HEAD;

        for (i = 2; i <= n; i++)
        {
            P->next = (struct node *)malloc(sizeof(struct node));
            if (P->next == NULL)
            {
                printf("Memory not available!\n");
                break;
            }
            else
            {
                P = P->next;
                printf("Enter power and co-eficient for term %d:",i);
                scanf("%d%f", &(P->pow), &(P->coeff));
            }
        }
        P->next = NULL;
    }
    return HEAD;
}
void display(struct node *HEAD)
{
    struct node *P;
    P = HEAD;
    printf("\nThe polynomial is as follows:\n");
    while (P != NULL)
    {
        printf("%f x^%d", (P->coeff), (P->pow));
        P = P->next;
        if (P != NULL)
        {
            printf(" + ");
        }
    }
}
struct node *add(struct node *HEAD1, struct node *HEAD2)
{
    struct node *L,*L1,*L2,*R;
    L1 = HEAD1;
    L2 = HEAD2;
    L = NULL;
    while(L1!=NULL && L2!=NULL)
    {
        if(L==NULL){
            L = R = (struct node *)malloc(sizeof(struct node));
        }
        else{
            R->next = (struct node *)malloc(sizeof(struct node));
            R = R->next;
        }
        if(L1->pow < L2->pow)
        {
            R->pow = L1->pow;
            R->coeff = L1->coeff;
            L1 = L1->next;
        }
        else if(L1->pow > L2->pow)
        {
            R->pow = L2->pow;
            R->coeff = L2->coeff;
            L2 = L2->next;
        }
        else
        {
            R->pow = L2->pow;
            R->coeff = L2->coeff + L1->coeff;
            L2 = L2->next;
            L1 = L1->next;
        }
        R->next = NULL;
    }
    while(L1 != NULL)
    {
        if(L==NULL){
            L = R = (struct node *)malloc(sizeof(struct node));
        }
        else{
            R->next = (struct node *)malloc(sizeof(struct node));
            R = R->next;
        }
        R->coeff = L1->coeff;
        R->pow = L1->pow;
        R->next = NULL;
        L1 = L1->next;
    }
    while(L2 != NULL)
    {
        if(L==NULL){
            L = R = (struct node *)malloc(sizeof(struct node));
        }
        else{
            R->next = (struct node *)malloc(sizeof(struct node));
            R = R->next;
        }
        R->coeff = L2->coeff;
        R->pow = L2->pow;
        R->next = NULL;
        L2 = L2->next;
    }
    return L;
}
struct node *multiply(struct node *T1, struct node *T2)
{
    struct node *R, *HEAD;
    HEAD = NULL;
    while(T2 != NULL)
    {
        if(HEAD==NULL){
            HEAD = R = (struct node *)malloc(sizeof(struct node));
        }
        else{
            R->next = (struct node *)malloc(sizeof(struct node));
            R = R->next;
        }
        R->pow = T1->pow + T2->pow;
        R->coeff = T1->coeff*T2->coeff;
        R->next = NULL;
        T2 = T2->next;
    }
    return HEAD;
}
