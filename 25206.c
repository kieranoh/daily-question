#include <stdio.h>
#include <string.h>

int main()
{

    float ave,sum_score=0,temp,sum_point=0;

    char info[60],point[3],score[3];
    for(int i=0;i<20;i++)
    {
        scanf("%s %s %s",info,point,score);

        if(score[0]=='P')
        {
            continue;
        }
        else if(score[0]=='F')
        {
            sum_point += (point[0]-'0');
        }
        else
        {
            temp = (score[0] - 'E') * (-1);
            if (score[1]=='+')
            {
                temp +=0.5;
            }
            temp *= (point[0]-'0');
            sum_score+=temp;
            sum_point +=(point[0]-'0');
            temp = 0;
        }
    }
    ave = sum_score/sum_point;
    printf("%f",ave);

    return 0;
}