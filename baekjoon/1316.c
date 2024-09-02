#include <stdio.h>
#include <string.h>

void init_li(int lst[26])
{
    for(int i=0;i<26;i++)
    {
        lst[i] = 0;
    }
}
int main()
{
    int Tc,cnt=0,len;
    int lst[26];
    init_li(lst);

    char input[101],before_char;
    scanf("%d",&Tc);


    for(int i=0;i<Tc;i++)
    {
        scanf("%s",input);
        len = strlen(input);

        for(int j=0;j<len;j++)
        {
            if(lst[input[j]-'a'] ==1 && before_char != input[j])
            {
                break;
            }
            if(lst[input[j]-'a'] ==0)
            {
                lst[input[j]-'a'] = 1;
                before_char = input[j];
            }

            if(j+1 == len)
            {
                cnt++;
            }
        }

        init_li(lst);

    }
    printf("%d",cnt);
}