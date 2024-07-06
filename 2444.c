#include <stdio.h>

int main()
{
    int num,cnt = 0,flg=0;
    scanf("%d",&num);
    cnt = num-1;

    for(int i=1;i<=num-1;i++)
    {
        for(int j=0;j<(num-i);j++)
        {
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
        
    }


    for(int i=0;i<=num-1;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf(" ");
        }
        for(int j=0;j<2*(num-i)-1;j++)
        {
            printf("*");
        }
        printf("\n");
        
    }

    return 0;
}