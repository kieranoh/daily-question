#include <stdio.h>

int main()
{
    int card_num,target,sum=0,temp;
    int list[101];
    scanf("%d %d",&card_num,&target);

    for(int i=0;i<card_num;i++)
    {
        scanf("%d",&list[i]);
    }

    for(int i=0;i<card_num-2;i++)
    {
        for(int j=i+1;j<card_num-1;j++)
        {
            for(int k=j+1;k<card_num;k++)
            {
                temp =list[i]+list[j]+list[k];
                if(temp==target)
                {   
                    sum = temp;
                    printf("%d",sum);

                    return 0;
                }
                if(temp<target && temp> sum)
                {
                    sum=temp;
                }
            }
        }
    }

    printf("%d",sum);

    return 0;

}