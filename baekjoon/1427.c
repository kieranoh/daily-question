#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long num;
    int *arr;
    int size = 0,capacity = 2,temp;
    scanf("%lld",&num);

    arr = (int *) malloc(capacity * sizeof(int));

    while(1)
    {
        if(num<10)
        {
            if(size == capacity)
            {
                capacity++;
                arr = (int *)realloc(arr,capacity * sizeof(int));
                arr[size] = num;
                size++;
                break;
            }

            arr[size] = num;
            size++;
            break;
        }
        temp = num%10;
        num/=10;
        if(size == capacity)
            {
                capacity*=2;
                arr = (int *)realloc(arr,capacity * sizeof(int));

            }
            arr[size] = temp;
            size++;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(arr[j-1] > arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=size-1;i>=0;i--)
    {
        printf("%d",arr[i]);
    }

    return 0;
}