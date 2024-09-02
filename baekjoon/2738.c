#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int arr_1[101][101],arr_2[101][101];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            scanf("%d",&arr_1[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr_2[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",arr_1[i][j] + arr_2[i][j]);
        }
        printf("\n");
    }

    return 0;

}