#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int age;
    char name[101];
}data;

int compare(const void*a, const void *b)
{
    data A = *(data*)a;
    data B = *(data*)b;
    if(A.age>B.age)
    {
        return 1;
    }
    else if(A.age<B.age)
    {
        return -1;
    }
    else{
        return 0;
    }
}

int main()
{
    int num;
    data *arr;
    scanf("%d",&num);

    arr = (data*)malloc(sizeof(data)*num);

    for(int i=0;i<num;i++)
    {
        scanf("%d %s",&arr[i].age,&arr[i].name);
    }

    qsort(arr,num,sizeof(data),compare);
        for(int i=0;i<num;i++)
    {
        printf("%d %s\n",arr[i].age,arr[i].name);
    }

    free(arr);
    
    return 0;

}