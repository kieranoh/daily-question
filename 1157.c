#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000001];
    int len,max_1=0,max_1_idx=-1,max_2_idx =-1,max_2=0,list[26]={0};

    scanf("%s",input);
    len = strlen(input);

    for(int i=0;i<len;i++)
    {
        if(input[i]>='a')
        {
            list[input[i]-'a']++;
        }
        else
        {
            list[input[i]-'A']++;
        }
    }

    for(int i=0;i<26;i++)
    {
        if(list[i]>=max_1)
        {
            max_2 = max_1;
            max_1=list[i];
            max_2_idx = max_1_idx;
            max_1_idx = i;
        }
    }

    if(max_1 == max_2)
    {
        printf("?");
        return 0;
    }
    else{
        printf("%c",max_1_idx+'A');
    }


    return 0;

}