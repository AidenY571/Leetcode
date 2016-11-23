/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        RandomListNode *new_head = new RandomListNode(0);
        RandomListNode *pass1 = new_head, *pass2 = head;

        unordered_map<RandomListNode *,RandomListNode *> m;

        while(head)
        {
            pass1->next = new RandomListNode(head->label);
            pass1 = pass1->next;
            m[head] = pass1;
            head = head->next;
        }

        pass1 = new_head->next;

        while(pass1)
        {
            pass1->random = m[pass2->random];
            pass1 = pass1->next;
            pass2 = pass2->next;
        }

        return new_head->next;
    }
};