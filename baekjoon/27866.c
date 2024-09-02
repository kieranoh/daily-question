#include <stdio.h>

int main()
{
    char input[1001];
    int n;
    scanf("%s",input);
    scanf("%d",&n);

    printf("%c",input[n-1]);

    return 0;
}