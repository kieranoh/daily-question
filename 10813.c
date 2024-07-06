#include <stdio.h>

void swap(int*a,int*b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int basket_num,change,a,b;
    int arr[100];
    scanf("%d %d",&basket_num,&change);

    for(int i=0;i<basket_num;i++)
    {
        arr[i] = i+1;
    }
    for (int i=0;i<change;i++)
    {
        scanf("%d %d",&a,&b);
        swap(&arr[a-1],&arr[b-1]);
    }
    for(int i=0;i<basket_num;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}