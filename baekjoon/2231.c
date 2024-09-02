#include <stdio.h>

int main()
{
    int num,result=0,sum,j;
    scanf("%d",&num);

    for(int i=0;i<num;i++)
    {
        sum = i;
        j=i;
        while(1)
        {
            
            sum+=j%10;
            j/=10;
            if(j<10)
            {
                sum+=j%10;
                break;
            }  
        }
    
        if(sum==num)
        {
            result = i;
            break;
        }
        
    }

    printf("%d",result);

    return 0;
}