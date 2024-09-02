#include <stdio.h>
#include <string.h>

int main()
{
    int Tc;
    char input[1000];

    scanf("%d",&Tc);

    for (int i=0;i<Tc;i++)
    {
        scanf("%s",input);
        printf("%c%c\n",input[0],input[strlen(input)-1]);
    }

    return 0;
}