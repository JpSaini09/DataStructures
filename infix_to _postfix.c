#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
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
int prec(char o)
{
    if(o == '+' || o == '-')
    return 1;
    if(o == '*' || o == '/')
    return 2;
    if(o == '^')
    return 3;
    else
    return 0;
}
int main(){
	char *str;
	int i = 0;
	scanf("%m[^\n]",&str);
	while(str[i] != '\0')
	{
	    if(isalnum(str[i]))
	    {
	        printf("%c",str[i]);
	    }
	    else if(str[i] == '(')
	    {
	        push('(');
	    }
	    else
	    {
	        if(str[i] == ')')
	        {
                 while(head->data != '(')
                 {
                     printf("%c",pop());
                 }
                 pop();
	        }
	        else
	        {
	            if(head == NULL)
                {
	                push(str[i]);
                }
	            else if(prec(str[i]) >= prec(head->data) || head->data == '(')
	            {
	                push(str[i]);
	            }
	            else
	            {
	                while(head !=NULL && head->data != '(')
	                {
	                    printf("%c",pop());
	                }
	                push(str[i]);
	            }
	        }
	    }
	i++;
	}
	while(head != NULL)
	{
	    printf("%c",head->data);
	    head = head->next;
	}
}
