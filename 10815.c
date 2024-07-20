#include <stdio.h>
#include <stdlib.h>
int compare(const void*a,const void*b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    return A>B;
}
int search(int *arr,int target,int size)
{
    if(arr[0]> target || arr[size-1] < target)
    {
        return 0;
    }
    int left;
    int right = size-1;
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(arr[mid]==target)
        {
            return 1;
        }
        if(arr[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid -1;
        }
    }
    return 0;
}
int main()
{
    int n,m;
    int *arr_n;
    int *arr_m;
    scanf("%d",&n);
    arr_n = (int* )malloc(sizeof(int) * n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr_n[i]);
    }
    scanf("%d",&m);
    arr_m = (int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr_m[i]);
    }
    qsort(arr_n,n,sizeof(int),compare);

    for(int i=0;i<m;i++)
    {
        printf("%d ",search(arr_n,arr_m[i],n));
    }

    return 0;
}