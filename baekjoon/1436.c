#include <stdio.h>

int main()
{
    int num,cnt=0,i = 665,temp,cntt=0;
    scanf("%d",&num);
    while(1)
    {
        temp = i;
        while(temp >=666)
        {
            if(temp%1000 == 666)
            {
                cnt++;
                break;
            }
            temp /=10;
            
        }
        if(cnt==num)
        {
            break;
        }
        i++;
    }
    printf("%d",i);
}