#include <stdio.h>
#include <string.h>
int main()
{
    char input[1000001];
    int cnt = 0,len;
    scanf("%[^\n]s",input);

    len = strlen(input);
    if (len == 1 && input[0] == ' ') {
		printf("0");
		return 0;
	}

    for(int i=1;i<len-1;i++)
    {

        if(input[i] ==' ')
        {
            cnt++;
        }
    }

    printf("%d",cnt+1);

    return 0;
}