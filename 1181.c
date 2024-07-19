#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void*a, const void *b)
{
    if(strlen((const char*)a)> strlen((const char*)b)) return 1;
    else if(strlen((const char*)a)< strlen((const char*)b)) return -1;
    else return strcmp((char*)a,(char*)b);
}

int main()
{
    char arr[20000][51];
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%s",&arr[i]);
    }
    qsort(arr,num,sizeof(arr[0]),compare);
    for(int i=0;i<num;i++)
    {
        if(strcmp(arr[i],arr[i+1])!=0 || i == num-1)
        {
            printf("%s\n",arr[i]);
        }
    }

    return 0;
}