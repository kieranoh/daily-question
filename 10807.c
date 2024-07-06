#include <stdio.h>

int main()
{
    int len,target,result=0;
    int arr[100];

    scanf("%d",&len);

    for(int i = 0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&target);

    for(int i = 0;i<len;i++)
    {
        if(arr[i]==target)
        {
            result++;
        }
    }

    printf("%d",result);

    return 0;
}