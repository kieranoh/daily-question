#include <stdio.h>

int main()
{
    int a,b,c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if(a==b && b==c && a==60)
    {
        printf("Equilateral");
    }
    else if((a+b+c)==180 &&(a==b || b==c || c==a))
    {
        printf("Isosceles");
    }
    else if (a+b+c ==180)
    {
        printf("Scalene");
    }
    else{
        printf("Error");
    }

    return 0;
    
}