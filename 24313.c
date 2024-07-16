#include <stdio.h>

int main()
{
    int a,a0,c,n0;
    scanf("%d %d %d %d",&a,&a0,&c,&n0);

    int res =1;

    if(c<a) res =0;
    if((c-a) *n0 <a0) res =0;

    printf("%d",res);

    return 0;
}