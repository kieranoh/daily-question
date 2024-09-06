/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    int num_a = *(int*) a;
    int num_b = *(int*) b;
    if(num_a > num_b)
    {
        return 1;
    }
    else if(num_a < num_b)
    {
        return -1;
    }
    else{
        return 0;
    }
}
int search(int target, int * arr,int size)
{
    if(arr[0] > target || arr[size-1]< target)
    {
        return -1;
    }
    int left = 0;
    int right = size-1;
    int mid;
    while(left<=right)
    {
        mid= (left+right)/2;
        if(arr[mid]==target)
        {
            return 1;
        }
        if(arr[mid]<target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    return 0;

}
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    qsort(nums,numsSize,sizeof(int),compare);
    struct ListNode * dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* temp = dummy;
    while(head != NULL)
    {
        if(search(head->val,nums,numsSize)==1)
        {
            temp->next = head->next;
        }
        else
        {
            temp = head;
        }
        head = head->next;
    }
    return dummy->next;
}