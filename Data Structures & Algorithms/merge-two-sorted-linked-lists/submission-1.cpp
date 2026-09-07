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
    ListNode* mergeTwoLists(ListNode* lp1, ListNode* lp2) {
        ListNode newHead(0, nullptr);
        /* i don't really need to do this given that parameters are passed by copy */
        ListNode* nh = &newHead;

        while (!(lp1 == nullptr && lp2 == nullptr)) {
            if (lp1 == nullptr) {
                nh->next = lp2;
                lp2 = lp2->next;
            } else if (lp2 == nullptr) {
                nh->next = lp1;
                lp1 = lp1->next;
            } else {
                if (lp1->val < lp2->val) {
                    nh->next = lp1;
                    lp1 = lp1->next;
                } else {
                    nh->next = lp2;
                    lp2 = lp2->next;
                }
            }
            nh = nh->next;
        }
        return newHead.next;
    }
};
