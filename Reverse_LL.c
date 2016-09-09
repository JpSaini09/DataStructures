#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
static struct node* head = NULL;
static int n = 0;
void lldata(int v)
{
    struct node* add = head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = v;
    head->next = add;
    n++;
}
struct node* revll()
{
    struct node* newnode;
    struct node* curr = NULL;
    while( head != NULL )
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head->data;
        newnode->next = curr;
        head=head->next;
        curr = newnode;
    }
    return newnode;
}
void display(struct node* temp)
{
    while(temp != NULL)
    {
        printf("*");
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int data;
    int i;
    for(i = 0; i < 4; i++)
    {
        scanf("%d",&data);
        lldata(data);
    }
    display(revll());
}
