#include <stdio.h>

int main()
{
    int basket_num,ball_num,temp_start,temp_end,temp_num;

    scanf("%d %d",&basket_num,&ball_num);

    int arr[100]={0};

    for(int i = 0;i<ball_num;i++)
    {
        scanf("%d %d %d",&temp_start,&temp_end,&temp_num);
        for(int j = temp_start-1;j<temp_end;j++)
        {
            arr[j] = temp_num;
        }

    }

    for(int i=0;i<basket_num;i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}