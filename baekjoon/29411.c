#include <stdio.h>
#include <string.h>

int main()
{
    char input[103];
    int cnt=0,len;

    scanf("%s",input);
    len = strlen(input);
    for(int i=0;i<len;i++)
    {
        if(input[i]=='c' && (input[i+1]=='=' ||input[i+1]=='-'))
        {

            cnt++;
            i++;
            continue;
        }
        else if(input[i]=='d'&&input[i+1]=='z'&&input[i+2]=='=')
        {

            cnt++;
            i = i+2;
            continue;
        }
        else if(input[i]=='d'&&input[i+1]=='-')
        {
            cnt++;
            i++;
            continue;
        }

        else if(input[i]=='l'&&input[i+1]=='j')
        {
                cnt++;
                i++;
                continue;
        }
        else if(input[i]=='n'&&input[i+1]=='j')
        {
                cnt++;
                i++;
                continue;
        }
        else if(input[i]=='s'&&input[i+1]=='=')
        {
                cnt++;
                i++;
                continue;
        }
        else if(input[i]=='z'&&input[i+1]=='=')
        {
                cnt++;
                i++;
                continue;
        }

        cnt++;
        

    }
    printf("%d",cnt);

    return 0;
}