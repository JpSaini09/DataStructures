//Finding the cap value that can be distributed among the array ...according to the budget passed..
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int s , i , j;
    scanf("%d",&s);
    double a[s];
    printf("Enter array\n");
    for(i = 0 ; i < s ; i ++)
    {
        scanf("%lf",&a[i]);
    }
    for(i = 0 ; i < s ; i ++)
    {
        printf("%lf ",a[i]);
    }
    printf("\n");
    for(i = 0 ;i < s ; i ++)
    {
        for(j = 0 ; j < s-1; j++)
        {
            if(a[j] > a[j+1])
            {
                double t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    for(i = 0 ; i < s ; i ++)
    {
        printf("%lf ",a[i]);
    }
    double budget , ans;
    printf("Enter Budget\n");
    scanf("%lf",&budget);
    for(i = 0 ; i < s ; i ++)
    {
        if(a[i]*(s-i) > budget)
        {
            ans = (budget/(s-i));
            break;
        }
        else
        {
            budget = budget - a[i];
        }
    }
    printf("\nCap Value : %lf",ans);
}
