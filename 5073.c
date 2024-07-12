#include <stdio.h>

void check(int a,int b, int c)
{

    int max;
    max = ((a>b) ? a:b);
    max = (max>c)? max:c;
    printf("%d\n",max);

    if(max>= a+b+c-max)
    {
        printf("Invaid\n");
    }
    else if(a==b && b==c)
    {
        printf("Equilateral\n");
    }
    else if(a==b || b==c || c==a)
    {
        printf("Isosceles\n");
    }
    else
    {
        printf("Scalene\n");
    }
}

int main()
{
    int a,b,c;

    

    while(1)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        check(a,b,c);

    }



    return 0;
    
}