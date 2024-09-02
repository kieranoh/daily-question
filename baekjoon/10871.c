#include <stdio.h>

int main()
{
    int len,target,temp;
    scanf("%d %d",&len,&target);

    for(int i=0;i<len;i++)
    {
        scanf("%d",&temp);
        if(temp < target)
        {
            printf("%d ",temp);
        }
    }

    return 0;
}