/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* i need to do this in a singular pass, since i have to pop
         * the last nth element i just need to track and determine the END-n element */

        ListNode newHead(0, head);
        ListNode* tmp = &newHead;
        ListNode* target = &newHead;

        while (tmp != nullptr) {
            if (n >= 0) {
                --n;
            } else {
                target = target->next;
                /*delayed node trakcing, node before before */
            }
            tmp = tmp->next;
        }

        if (target->next != nullptr) {
            target->next = target->next->next;
        } else {
            target->next = nullptr;
        }

        return newHead.next;
    }
};
