#include <stdio.h>

int main()
{
    int a,b;

    scanf("%d %d",&a,&b);

    while(a!=b)
    {
        if(b%a==0)
        {
            printf("factor\n");
        }
        else if(a%b==0)
        {
            printf("multiple\n");
        }
        else
        {
            printf("neither\n");
        }
        scanf("%d %d",&a,&b);
    }

    return 0;
}