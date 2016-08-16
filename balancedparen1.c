#include<stdio.h>
#include"stack.h"
main()
{
    char* str;
    scanf("%m[^\n]",&str);
    int s = 0;
    int i;
    while(str[s]!='\0')
    {
        s= s + 1;
    }
    for(i = 0; i <= s; i++)
    {
        if(str[i] == '(')
            push((void*)'(');
        else if(str[i] == ')' && size() != 0)
            pop((void*)'(');
        else if(str[i] == ')' && size() == 0)
        {
             push((void*)1);
             break;
        }    
    }
    if(size() == 0)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}
