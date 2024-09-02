#include <stdio.h>

int main()
{
    int num;

    scanf("%d",&num);

    for (num;num>0;num=num-4)
    {
        printf("long ");
    }
    printf("int");

    return 0;
}