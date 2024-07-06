#include <stdio.h>

int main()
{
    int temp,j=0;
    int arr[30] ={0};
    int result[2];

    for(int i=0;i<28;i++)
    {
        scanf("%d",&temp);
        arr[temp-1] = 1;
    }

    for(int i=0;i<30;i++)
    {

        if(arr[i]!=1)
        {

            result[j]=i+1;
            j++;
        }
    }

    if(result[0]>result[1])
    {
        j = result[0];
        result[0] = result[1];
        result[1] = j;
    }

    printf("%d\n%d",result[0],result[1]);

    return 0;
}