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
    int n = 0;
    int s1 = 0;
    int s2 = 0;
    scanf("%d",&n);
    while(n != -1)
    {
        s1++;
        head1 = push(n,head1);
        scanf("%d",&n);
    }
    n = 0;
    scanf("%d",&n);
    while(n != -1)
    {
        s2++;
        head2 = push(n,head2);
        scanf("%d",&n);
    }
    int sum;
    int c = 0;
    int d= 0;
    if(s1 > s2)
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
        head3 = push(sum,head3);
    }
    else if(s1 < s2)
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
        head3 = push(sum,head3);
    }

    while(head3 != NULL)
    {
        printf("%d",head3->data);
        head3 = head3->next;
    }

}
