/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num1=0,num2=0,carry = 0,sum;
    
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;

    struct ListNode* current = result;

    while(l1 != NULL ||l2 != NULL)
    {
        num1 = (l1 != NULL) ? l1->val:0;
        num2 = (l2 != NULL) ? l2->val:0;
        sum = carry + num1+num2;

        carry = sum/10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = sum%10;
        current->next->next = NULL;
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;

    }
    if(carry>0)
    {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = carry;
        current->next->next = NULL;
        current = current->next;
    }

    return result->next;
}