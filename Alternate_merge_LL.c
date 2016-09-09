#include <stdlib.h>
#include <math.h>
#include <stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* push(int x , struct node* head)
{
    struct node *add = head;
    head = (struct node*)malloc(sizeof(struct node));
    (head)->data = x;
    (head)->next = add;
    return head;
}
void merge(struct node **a,struct node **b)
{
     struct node* h1 = *a;
     struct node* h2 = *b;
     struct node* h3;
     while( (h1) != NULL && (h2) != NULL)
     {
         (h3) = (h1)->next;
         (h1)->next = (h2);
         (h2) = (h2)->next;
         (h1) = (h1)->next;
         (h1)->next = (h3);
         (h1) = (h1)->next;
     }
     while((*a) != NULL)
     {
         printf("%d ",(*a)->data);
         a = &(*a)->next;
     }
     printf("\n");
     if(h2 != NULL)
     {
         while(h2 != NULL)
         {
         printf("%d ",h2->data);
         h2 = h2->next;
         }
     }
}
int main()
{
     int l1,l2;
     int i ,t;
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     scanf(" %d%d",&l1,&l2);
     for(i = 0; i < l1; i ++)
     {
         scanf("%d",&t);
         head1 = push(t,head1);
     }
     struct node* t1 = head1,*next=NULL,*prev;
     while( t1 != NULL)
     {
         prev = t1->next;
         t1->next = next;
         next = t1;
         t1 = prev;
     }
     head1 = next;
     for(i = 0; i < l2; i ++)
     {
         scanf("%d",&t);
         head2 = push(t,head2);
     }
     t1 = head2;
     next = NULL;
     while( t1 != NULL)
     {
         prev = t1->next;
         t1->next = next;
         next = t1;
         t1 = prev;
     }
     head2 = next;
     merge(&head1,&head2);
}
