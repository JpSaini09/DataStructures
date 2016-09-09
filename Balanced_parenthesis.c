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
    int v = head->data;
    head = head->next;
    n--;
    return v;
}
int size()
{
    return n;
}
char check(char x)
{
    if(x == '}')
       return '{';
    else if(x == ')')
       return '(';
    else
       return '[';
}
int main()
{
	char* str;
	scanf("%m[^\n]",&str);
	int s = 0;
	int i;
	while(str[s] != '\0')
    {
        s++;
    }
    for(i = 0; i < s; i ++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(str[i]);
        }
        else
        {
            if( pop() != check(str[i]))
            {
                push((char)1);
                break;
            }
        }
    }
    if(size() == 0)
       printf("true\n");
    else
       printf("false\n");
}
