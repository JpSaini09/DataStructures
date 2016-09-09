#include <stdlib.h>
#include <math.h>
#include <stdio.h>
struct node
{
    char data;
    struct node* next;
};
static struct node* head = NULL;
static int n = 0;
void push(char t)
{
    struct node* add = head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data=t;
    head->next=add;
    n++;
}
char pop()
{
    char v = head->data;
    head = head->next;
    n--;
    return v;
}
int size()
{
    return n;
}
int main(){
	char *str;
	scanf("%m[^\n]",&str);
	int s=0,i,j,f = 0;
	while(str[s] != '\0')
	{
	    s++;
	}
	if(str[s/2] != 'c')
	{
	        f = 1;
	}
	else
	{
	        for(i = 0; i < (s/2); i++)
	        {
	            push(str[i]);
	        }
	        j = i + 1;
	        for(i = j; i < s; i++)
	        {
	            char t = pop();
	            if(t == str[i])
	            {
	                f = 0;
	            }
	            else
	            {
	                f = 1;
	                break;
	            }
	        }
	}
	if(f == 1)
	    printf("0");
	else
	    printf("1");
}
