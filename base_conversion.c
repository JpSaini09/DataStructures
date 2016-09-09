#include <stdlib.h>
#include <math.h>
#include <stdio.h>
struct node
{
    int data;
    struct node* next;
};
static struct node* head = NULL;
static int n = 0;
void push(int t)
{
    struct node* add = head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data=t;
    head->next=add;
    n++;
}
int pop()
{
    int v = head->data;
    head = head->next;
    n--;
    return v;
}
int size()
{
    return n;
}
int main()
{
	int num;
	int base;
	int r;
	scanf(" %d%d",&num,&base);
	while(num != 1)
	{
	    r = num%base;
	    push(r);
	    num = num/base;
	}
	push(1);
	while(size() != 0)
	{
	    printf("%d",pop());
	}
}
