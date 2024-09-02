#include <stdio.h>

int main()
{
    int cnt[10001] = {0,};
    int num,temp;

    scanf("%d",&num);

    for(int i=0;i<num;i++)
    {
        scanf("%d",&temp);
        cnt[temp]++;
    }
    for(int i=0;i<10001;i++)
    {
        for(int j=0;j<cnt[i];j++)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}