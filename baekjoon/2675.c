#include <stdio.h>
#include <string.h>

int main()
{
    int Tc,cnt;
    char input[21];
    scanf("%d",&Tc);

    for(int i=0;i<Tc;i++)
    {
        scanf("%d %s",&cnt,input);
        for(int j=0;j<strlen(input);j++)
        {
            for(int m=0;m<cnt;m++)
            {
                printf("%c",input[j]);
            }   
        }
        printf("\n");
    }

    return 0;
}