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
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int j;
	int i , top , area = 0 , marea = 0;
	for(j = 0; j < n ; j++)
	{
	    scanf("%d",&arr[j]);
	}
	push(0);
	i = 1;
	while(i < n)
	{
	    if(head == NULL)
	    {
	        push(i);
	        i++;
	    }
	    else if(arr[i] >= arr[head->data])
	    {
	        push(i);
	        i++;
	    }
	    else
	    {
	        if(head->next == NULL)
	        {
	            area = arr[pop()]*i;
	        }
	        else
	        {
	            area = arr[pop()]*(i - (head->data) - 1);
	        }
	        if(area>=marea)
	        {
	            marea = area;
	        }
	    }
    }
    while(head != NULL)
        {
            if(head->next == NULL)
	        {
	            area = arr[pop()]*i;
	        }
	        else
	        {
	            area = arr[pop()]*(i - (head->data) - 1);
	        }
	        if(area >= marea)
	        {
	            marea = area;
	        }
	}
	printf("%d",marea);
}
