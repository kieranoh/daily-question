#include <stdio.h>


int main()
{
    char input[5][15] ={0,};

    for(int i=0;i<5;i++)
    {
        scanf("%s",input[i]);
    }
    
    for(int j=0;j<15;j++)
    {
        for(int i=0;i<5;i++)
        {
            if(input[i][j]!='\0')
            {
                printf("%c",input[i][j]);
            }
            
        }
    }

    return 0;

}