#include <stdio.h>

int main()
{
    int money,result,temp,tc;

    scanf("%d",&tc);

    for(int i=0;i<tc;i++)
    {
        scanf("%d",&money);

        printf("%d ",money/25);
        money%=25;

        printf("%d ",money/10);
        money%=10;

        printf("%d ",money/5);
        money%=5;

        printf("%d \n",money);
    }


    return 0;
}