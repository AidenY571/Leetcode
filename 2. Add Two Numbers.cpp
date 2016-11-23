class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;

        ListNode* res = new ListNode(1);
        ListNode* l = res;

        while(l1 || l2 || carry)
        {
            if(l1) {carry += l1->val;l1=l1->next;}
            if(l2) {carry += l2->val;l2=l2->next;}
            l->next = new ListNode(carry%10);
            carry /= 10;
            l = l->next;
        }
        return res->next;
    }
};