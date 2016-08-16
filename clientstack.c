#include<stdio.h>
#include"stack.h"
main()
{
    char val = 'c';
    void* val1;
    val1 = &val;
    push(val1);
    push(val1);
    push(val1);
    printf("data: %c\n",*(char*)pop());
    printf("s: %d\n",size());
    printf("data: %c\n",*(char*)pop());
    printf("s: %d\n",size());
    printf("data: %c\n",*(char*)pop());
    printf("s: %d\n",size());
}
