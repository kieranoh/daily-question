#include <stdio.h>

int count_repaint(char map[51][51],int x,int y,char start)
{
    int cnt = 0;
    char current_color = start;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(map[x+i][y+j]!=current_color)
            {
                cnt++;
            }
            current_color = (current_color == 'B') ? 'W':'B';
        }
        current_color = (current_color == 'B') ? 'W':'B';
    }

    return cnt;
}

int main()
{
    int n,m,min=65,temp;
    char map[51][51];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&map[i]);
    }
    for(int i=0;i<=n-8;i++)
    {
        for(int j=0;j<=m-8;j++)
        {
            temp = count_repaint(map,i,j,'W');
            min = (temp < min) ? temp:min;
            temp = count_repaint(map,i,j,'B');
            min = (temp < min) ? temp:min;
        }
    }

    printf("%d",min);

    return 0;
}