

void dfs(int curr, int*idx, int *result, int n)
{
    if(curr>n)
    {
        return;
    }
    result[(*idx)] = curr;
    (*idx)++;
    for(int i=0;i<=9;i++)
    {
        dfs(curr*10+i,idx,result,n);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*n);
    int idx = 0;

    for(int i=1; i<=9;i++)
    {
        dfs(i,&idx,result,n);
    }    
    
    *returnSize = idx;
    
    return result;
}