/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*queriesSize);
    int temp = 0;
    for(int i=0; i<queriesSize;i++)
    {
        temp = 0;

        for(int j=queries[i][0];j<=queries[i][1];j++)
        {
            temp = temp ^ arr[j];
        }
        result[i] = temp;
        printf("%d ",result[i]);
    }
    *returnSize = queriesSize;
    return result;
}