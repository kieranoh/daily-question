#include <stdio.h>

int main()
{
    int max=0,max_i=0,max_j=0,temp;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&temp);
            if (temp > max)
            {
                max = temp;
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("%d\n%d %d",max,max_i+1,max_j+1);
   
    return 0;

}