#include <stdio.h>
#include <string.h>

int main()
{

    int num,len,result = 0,temp=1,temp_num;
    char input[1000];

    scanf("%s %d",input,&num);

    len=strlen(input);

    for(int i=len-1;i>=0;i--)
    {
        if(input[i]>='A')
        {
            temp_num = input[i]-'A'+10;
        }
        else{
            temp_num = input[i]-'0';
        }
        result += temp_num*temp;
        temp *=num;
    }

    printf("%d",result);

    
    return 0;
}