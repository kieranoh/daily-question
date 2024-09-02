#include <stdio.h>

int main()
{
    int num,cnt=0,target;

    scanf("%d %d",&num,&target);

    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            cnt++;
            if(cnt==target)
            {
                printf("%d",i);
                return 0;
            }
        }
    }

    printf("0");

    return 0;
}