#include <stdio.h>

int main()
{
    int num,result =2;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {   
        result += result-1;
    }
    result *= result;

    printf("%d",result);

    return 0;

}