#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* push(int v , struct node* head)
{
    struct node* add = head;
    head = (struct node*)malloc(sizeof(struct node*));
    head->data = v;
    head->next = add;
    return head;
}
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    int n1 , n2 , i , n;
    int s1 = 0;
    int s2 = 0;
    scanf("%d%d",&n1,&n2);
    for(i = 0 ; i < n1 ; i ++)
    {
        scanf("%d",&n);
        head1 = push(n,head1);
    }
    for(i = 0; i < n2 ; i ++)
    {
        scanf("%d",&n);
        head2 = push(n,head2);
    }
    int sum;
    int c = 0;
    int d= 0;
    if(n1 > n2)
    {
        while(head2!= NULL)
        {
        sum = head1->data + head2->data;
        sum  = sum + c;
        c = sum/10;
        d = sum%10;
        head3 = push(d ,head3);
        head1 = head1->next;
        head2 = head2->next;
        }
        while((head1->next) != NULL)
        {
            sum = head1->data + 0;
            sum  = sum + c;
            c = sum/10;
            d = sum%10;
            head3 = push(d ,head3);
            head1 = head1->next;
        }
        sum = head1->data + 0;
        sum = sum + c;
        int x = sum%10;
        head3 = push(x,head3);
        sum  = sum/10;
        if(sum >0)
           head3 = push(sum,head3);
    }
    else if(n1 < n2)
    {
        while(head1!= NULL)
        {
        sum = head1->data + head2->data;
        sum  = sum + c;
        c = sum/10;
        d = sum%10;
        head3 = push(d ,head3);
        head1 = head1->next;
        head2 = head2->next;
        }
        while((head2->next) != NULL)
        {
            sum = head2->data + 0;
            sum  = sum + c;
            c = sum/10;
            d = sum%10;
            head3 = push(d ,head3);
            head2 = head2->next;
        }
        sum = head2->data + 0;
        sum = sum + c;
        int x = sum%10;
        head3 = push(x,head3);
        sum  = sum/10;
        if(sum >0)
           head3 = push(sum,head3);
    }
    else
    {
        while((head1->next)!= NULL)
        {
        sum = head1->data + head2->data;
        sum  = sum + c;
        c = sum/10;
        d = sum%10;
        head3 = push(d ,head3);
        head1 = head1->next;
        head2 = head2->next;
        }
        sum = head1->data + head2->data;
        sum = sum + c;
        int x = sum%10;
        head3 = push(x,head3);
        sum  = sum/10;
        if(sum >0)
            head3 = push(sum,head3);
    }

    while(head3 != NULL)
    {
        printf("%d ",head3->data);
        head3 = head3->next;
    }

}

