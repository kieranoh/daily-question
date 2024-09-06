#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int sum=0,temp;
    int *result;
    for(int i=0;i<rollsSize;i++)
    {
        sum+=rolls[i];
    }
    sum = (rollsSize + n)*mean - sum;

    if(sum < n|| sum > 6*n)
    {
        *returnSize = 0;
        return NULL;
    }
    result = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    temp = sum/n;
    for(int i=0;i<n;i++)
    {
        if(sum == temp * (n-i))
        {
            result[i] = temp;
            sum -= temp;
        }
        else
        {
            result[i] = temp+1;
            sum -=temp+1;
        }
        
    }
    return result;
}