/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b)
{
    int n;
    if(a<b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(b!=0)
    {
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode *result;
    int temp;
    result = head;
    while(head->next !=NULL)
    {
        temp = gcd(head->val,head->next->val);
        struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode));
        res->val = temp;
        res->next = head->next;
        head->next = res;

        head = head->next->next;
    }

    return result;
}