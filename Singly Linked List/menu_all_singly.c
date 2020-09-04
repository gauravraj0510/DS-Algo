#include <stdio.h>
#include <stdlib.h>

struct node *create(int);
void display(struct node *);
struct node *insertStart(struct node *);
void *insertEnd(struct node *);
void insertMid(struct node *);
void *deleteEnd(struct node *);
struct node *deleteStart(struct node *);
struct node *deleteMid(struct node *);
struct node *reverse(struct node *);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    printf("Enter the number of nodes:\n");
    int n;
    scanf("%d", &n);
    struct node *HEAD;
    HEAD = create(n);
    display(HEAD);
    printf("\n");
    int ch, choice;
    do
    {
        printf("\nEnter the operation number to be performed: ");
        printf("\n1)Insert new Head\n2)Insert new Tail\n3)Insert new node in between\n4)Delete Head\n5)Delete Tail\n6)Delete node from middle\n7)Reverse linked list\nEnter your choice number: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            HEAD = insertStart(HEAD);
            display(HEAD);
            break;

        case 2:
            insertEnd(HEAD);
            display(HEAD);
            break;

        case 3:
            insertMid(HEAD);
            display(HEAD);
            break;

        case 4:
            HEAD = deleteStart(HEAD);
            display(HEAD);
            break;

        case 5:
            deleteEnd(HEAD);
            display(HEAD);
            break;

        case 6:
            HEAD = deleteMid(HEAD);
            display(HEAD);
            break;

        case 7:
            HEAD = reverse(HEAD);
            display(HEAD);
            break;

        default:
            printf("\nWrong input! Try Again!");
            break;
        }

        printf("\n\nDo you want to try again?\n1)Yes\n2)No\nEnter your choice number: ");
        scanf("%d", &choice);
    } while (choice == 1);
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
        printf("\nEnter data for node 1:");
        scanf("%d", &(HEAD->data));
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
                printf("Enter data for node %d:", i);
                scanf("%d", &(P->data));
            }
            P->next = NULL;
        }
    }
    return HEAD;
}

void display(struct node *HEAD)
{
    struct node *P;
    P = HEAD;
    printf("\nData stored in linked list are:\n");
    while (P != NULL)
    {
        printf("\t %d", (P->data));
        P = P->next;
    }
}

struct node *insertStart(struct node *HEAD)
{
    struct node *P;
    P = (struct node *)malloc(sizeof(struct node));
    if (P == NULL)
    {
        printf("\nMemory cannot be allocated");
    }
    else
    {
        printf("\nEnter data for new Head:");
        scanf("%d", &(P->data));
        P->next = HEAD;
        HEAD = P;
    }
    return HEAD;
}

void *insertEnd(struct node *HEAD)
{
    struct node *P, *TEMP;
    TEMP = HEAD;
    P = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for new Tail:");
    scanf("%d", &(P->data));
    while (TEMP->next != NULL)
    {
        TEMP = TEMP->next;
    }
    TEMP->next = P;
    P->next = NULL;
}

void insertMid(struct node *HEAD)
{
    struct node *TEMP, *P;
    int key;
    printf("\nEnter data of node after which new node has to be inserted :");
    scanf("%d", &key);
    P = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &(P->data));
    TEMP = HEAD;
    while (TEMP != NULL && key != (TEMP->data))
    {
        TEMP = TEMP->next;
    }
    if (TEMP != NULL)
    {
        P->next = TEMP->next;
        TEMP->next = P;
    }
}

void *deleteEnd(struct node *HEAD)
{
    struct node *TEMP;
    if (HEAD->next == NULL)
    {
        free(HEAD);
        HEAD = NULL;
    }
    else
    {
        TEMP = HEAD;
        while (TEMP->next->next != NULL)
        {
            TEMP = TEMP->next;
        }
        free(TEMP->next);
        TEMP->next = NULL;
    }
}

struct node *deleteStart(struct node *HEAD)
{
    struct node *P;
    P = HEAD;
    HEAD = HEAD->next;
    free(P);
    return HEAD;
}

struct node *deleteMid(struct node *HEAD){
    struct node *PREV, *TARGET;
    int key;
    printf("\nEnter the data of node to be deleted:");
    scanf("%d",&key);
    PREV = HEAD;
    while (key != PREV->next->data && PREV->next != NULL)
    {
        PREV = PREV->next;
    }
    if(PREV->next != NULL){
        TARGET = PREV->next;
        PREV->next = PREV->next->next;
    }
    free(TARGET);
    return HEAD;
}

struct node *reverse(struct node *HEAD){
    struct node *P,*Q,*R;
    P = NULL;
    Q = HEAD;
    R = HEAD->next;
    while (Q != NULL)
    {
        Q->next = P;
        P = Q;
        Q = R;
        if(R != NULL){
            R = R->next;
        }
    }
    HEAD = P;
    return HEAD;    
}