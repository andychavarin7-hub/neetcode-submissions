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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *ret = res;
        while(!(l1==nullptr && l2==nullptr)){

            int nVal= res->val;
            if(l1!=nullptr){
                nVal += l1->val;
                l1 = l1->next;
            }

            if(l2!=nullptr){
                nVal += l2->val;
                l2 = l2->next;
            }

            res->val = nVal%10;
            if((l1==nullptr && l2==nullptr) && nVal/10 ==0){
                break;
            }
            res->next = new ListNode(nVal/10);
            res = res->next;
        }

        return ret;
    }
};
