
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    if(head == NULL || m==0 || n==0)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int **result;

    int up=0;
    int down = m-1;
    int left = 0; 
    int right = n-1;

    
    result = (int**)malloc(sizeof(int*)*m);

    (*returnColumnSizes) = (int*)malloc(sizeof(int) * m);

    for(int i=0;i<m;i++)
    {
        result[i] = (int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
        for(int j=0;j<n;j++)
        {
            result[i][j]=-1;
        }
    }
    while(head && left<= right && up <= down)
    {
        for(int j= left; j<= right; j++)
        {
            if(!head)
            {
                break;
            }
            result[up][j] = head->val;
            head = head->next;
        }
        up++;
        for(int i= up; i <= down; i++)
        {
            if(!head)
            {
                break;
            }
            result[i][right] = head->val;
            head = head->next;
        }
        right--;
        for(int j = right; j >= left; j--)
        {
            if(!head)
            {
                break;
            }
            result[down][j] = head->val;
            head = head->next;
        }
        down--;
        for(int i=down; i>= up; i--)
        {
            if(!head)
            {
                break;
            }
            result[i][left] = head->val;
            head = head->next;
        }
        left ++;
    }
    *returnSize = m;
    return result;
}