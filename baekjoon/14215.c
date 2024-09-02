#include <stdio.h>

int main()
{
    int a,b,c,max,result;

    scanf("%d %d %d",&a,&b,&c);

    max = (a>b) ? a:b;
    max = (max>c) ? max : c;

    if (max >= a+b+c-max)
    {
        result = 2*(a+b+c-max) -1;
    }
    else
    {
        result = a+b+c;
    }

    printf("%d",result);

    return 0;
}
