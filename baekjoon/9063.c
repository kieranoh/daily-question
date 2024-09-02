#include <stdio.h>
#include <math.h>

int main()
{
    int tc,area,x,y,min_x=100000,min_y=100000,max_x=-100000,max_y=-100000;

    scanf("%d",&tc);

    for(int i=0;i<tc;i++)
    {
        scanf("%d %d",&x,&y);
        if(x<min_x)
        {
            min_x = x;
        }
        if (x>max_x)
        {
            max_x = x;
        }
        if(y<min_y)
        {
            min_y = y;
        }
        if (y>max_y)
        {
            max_y = y;
        }      

    }
    if(tc==1)
    {
        printf("0");
    }
    else
    {
        
        area = (max_x-min_x)*(max_y-min_y);
        printf("%d",abs(area));
    }

    return 0;
}