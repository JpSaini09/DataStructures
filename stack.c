#include<stdio.h>
#include<malloc.h>
#include"stack.h"
struct node
{
    void* data;
    struct node* next; 
};
static struct node* head = NULL;
static int n = 0;
void push(void* value)
{
    struct node* add = head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = value;
    head->next = add;
    n++;
}
void* pop()
{
    void* val = head->data;
    head = head->next;
    n--;
    return val;
}
int isempty()
{
    return head == NULL;
}
int size()
{
    return n;
}
