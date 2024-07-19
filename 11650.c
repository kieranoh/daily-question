#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
}coord;

int compare(const void*a, const void *b)
{
    coord A = *(coord *) a;
    coord B = *(coord *) b;
    if(A.x > B.x)
    {
        return 1;
    }
    else if(A.x == B.x)
    {
        if(A.y> B.y)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
int main()
{
    int num;
    scanf("%d",&num);

 
    coord arr[num];
    
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    qsort(arr,num,sizeof(coord),compare);
    for(int i=0;i<num;i++)
    {
        printf("%d %d\n",arr[i].x,arr[i].y);
    }

    return 0;
}
