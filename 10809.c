#include <stdio.h>
#include <string.h>

int main()
{
    int target[26];
    for (int i=0;i<26;i++)
    {
        target[i]=-1;
    }

    char input[101];
    scanf("%s",input);

    for(int i=0; i<strlen(input);i++)
    {
        if(target[input[i]-'a']==-1)
        {
            target[input[i]-'a'] = i;
        }
    }

    for (int i=0;i<26;i++)
    {
        printf("%d ",target[i]);
    }

    return 0;
}