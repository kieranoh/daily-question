#include <stdio.h>

int main()
{
    int Tc,start,end,cnt=0;

    int paper[100][100] = {0,};

    scanf("%d",&Tc);

    for(int i=0;i<Tc;i++)
    {
        scanf("%d %d",&start,&end);

        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                paper[start+j-1][end+k-1] = 1;
            }
        }
    }

    for(int j=0;j<100;j++)
        {
            for(int k=0;k<100;k++)
            {
                if(paper[j][k]==1)
                {
                    cnt++;
                }
            }
        }
        
    printf("%d",cnt);

    return 0;
}