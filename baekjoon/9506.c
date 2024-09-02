#include <stdio.h>

int main()
{
    int num,cnt=0,temp=0;
    int list[100000]={0,};

    scanf("%d",&num);
    while(num!=-1)
    {
        for(int i=1;i<num;i++)
        {
            if(num%i==0)
            {   
                list[cnt]=i;
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            temp += list[i]; 
        }
        if(temp==num)
        {
            printf("%d = %d",num,list[0]);
            for(int i=1;i<cnt;i++)
            {
                printf(" + %d",list[i]); 
            }
        }
        else
        {
            printf("%d is NOT perfect.",num);
        }
        printf("\n");
        scanf("%d",&num);

        temp = 0;
        cnt = 0;
        
    }

    return 0;
}