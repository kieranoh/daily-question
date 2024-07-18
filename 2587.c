#include <stdio.h>

int main()
{
    int ave=0,temp;
    int arr[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
        ave+=arr[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("%d\n%d",ave/5,arr[2]);

    return 0;
}