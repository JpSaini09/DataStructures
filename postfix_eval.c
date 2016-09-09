#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
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
	char *str;
	scanf("%m[^\n]",&str);
	int s = 0 , i;
	int t;
	char *p ;
	p = strtok (str," ");
	while( p != NULL )
	{
	    if((strcmp(p,"+") == 0) || (strcmp(p,"-") == 0) || (strcmp(p,"*") == 0) || (strcmp(p,"/") == 0))
	    {
	        int a;
	        a = pop();
	        int b;
	        b = pop();
	        if(strcmp(p,"+") == 0)
	        {
	           t = (a + b);
	           push(t);
	        }
	        else if(strcmp(p,"-") == 0)
	        {
	           t = (b - a);
	           push(t);
	        }
	        else if(strcmp(p,"*") == 0)
	        {
	           t = (b * a);
	           push(t);
	        }
	        else
	        {
	           t = (b / a);
	           push(t);
	        }
	    }
	    else
	    {
	        t = atoi(p);
	        push(t);
	    }
	    p = strtok(NULL," ");
	}
	int x = pop();
	printf("%d",x);
}
