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


        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        ListNode *res = new ListNode(0);
        ListNode *ret = res;
        int carry = 0;
        while(!(tmp1==nullptr && tmp2==nullptr)){

            int nVal= res->val;
            if(tmp1!=nullptr){
                nVal += tmp1->val;
                tmp1 = tmp1->next;
            }

            if(tmp2!=nullptr){
                nVal += tmp2->val;
                tmp2 = tmp2->next;
            }

            res->val = nVal%10;
            if((tmp1==nullptr && tmp2==nullptr) && nVal/10 ==0){

            } else {
                res->next = new ListNode(nVal/10);
            }
            
            res = res->next;
        }

        return ret;
    }
};
