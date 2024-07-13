#include <stdio.h>

int main()
{
    int a,b,c,max;

    

    while(1)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        max = ((a>b) ? a:b);
        max = (max>c)? max:c;

        if(max>= a+b+c-max)
        {
            printf("Invalid\n");
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



    return 0;
    
}