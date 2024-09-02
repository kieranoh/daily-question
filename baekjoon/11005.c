#include <stdio.h>
#include <string.h>

int main()
{

    int num,len,temp,temp_num,i=0,cnt=0;
    char input[1000];
    char result[1000];

    scanf("%d %d",&temp_num,&num);


    while(1)
    {
        if(temp_num<=0)
        {
            break;
        }
        temp = temp_num%num;
        temp_num-=temp;
        temp_num = temp_num/num;

        if(temp >=10)
        {
            result[i] = 'A' + temp-10;
        }
        else
        {
            result[i] = '0'+temp;
        }
        i++; 
    }

    len = strlen(result);
    for(int j=1;j<=len;j++)
    {
        printf("%c",result[len-j]);
    }

    
    return 0;
}