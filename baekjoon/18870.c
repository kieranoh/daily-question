#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int num;
    int pos;
    int index;
}number;

int compare_index(const void*a, const void*b)
{
    number A = *(number*)a;
    number B = *(number*)b;

    if(A.index > B.index)
    {
        return 1;
    }
    else{
        return -1;
    }
}

int compare_num(const void*a, const void*b)
{
    number A = *(number*)a;
    number B = *(number*)b;

    if(A.num > B.num)
    {
        return 1;
    }
    else {
        return -1;
    }
}

int main()
{
    int a,j=0;
    scanf("%d",&a);
    number *arr;
    arr = (number*)malloc(sizeof(number)*a);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&arr[i].num);
        arr[i].index = i;
    }
    qsort(arr,a,sizeof(number),compare_num);
    for(int i=0;i<a;i++)
    {
        arr[i].pos = j;
        if(arr[i].num != arr[i+1].num || i == a-1)
        {
            j++;
        }

        
    }
    qsort(arr,a,sizeof(number),compare_index);
    for(int i=0;i<a;i++)
    {
        printf("%d ",arr[i].pos);
    }

    return 0;

}