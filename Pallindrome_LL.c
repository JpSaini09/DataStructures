#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int val;
    struct node* next;

};
typedef struct node listnode;
listnode* head = NULL;
void push(int d)
{
    listnode* add = head;
    head = (listnode*)malloc(sizeof(listnode));
    head->val=d;
    head->next=add;
}
int lPalin(listnode* A)
{
    listnode* A1 = A;
    listnode* A2 = A;
    listnode* A3;
    listnode* current;
    listnode* next = NULL;
    listnode* prev;
    int s = 0;
    int i;
    while(A1 != NULL)
    {
        s++;
        A1 = A1->next;
    }
    if(s>1)
    {
    if(s%2 == 0)
    {
        for(i = 0; i < ((s/2)-1); i++)
        {
            A2 = A2->next;
        }
        A3 = A2->next;
        A2->next = NULL;
        while(A3 != NULL)
        {
            prev = A3->next;
            A3->next = next;
            next = A3;
            A3 = prev;
        }
        A3 = next;
        while(A != NULL || A3 != NULL)
        {
            if(A->val != A3->val)
                return 0;

            A = A->next;
            A3 = A3->next;
        }
    return 1;
    }
    else
    {
        for(i = 0; i < ((s/2)-1); i++)
        {
            A2 = A2->next;
        }
        A3 = (A2->next)->next;
        A2->next = NULL;
        while(A3 != NULL)
        {
            prev = A3->next;
            A3->next = next;
            next = A3;
            A3 = prev;
        }
        A3 = next;
        while(A != NULL || A3 != NULL)
        {
            if(A->val != A3->val)
                return 0;

            A = A->next;
            A3 = A3->next;
        }
    return 1;
    }
    }
    else
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i , v;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&v);
        push(v);
    }
    int y = lPalin(head);
    printf("%d",y);
}
