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
    void reorderList(ListNode* head) {
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr->next!=nullptr){

            ListNode *tmp = curr;
            ListNode *prev = curr;
            ListNode *tmp2 = curr->next;

            /*go find the next and last ptr*/
            //std::cout << "im here \n";
            while(tmp->next !=nullptr){
                prev = tmp;
                tmp = tmp->next;
            }
             
            /*found the last node */
            prev->next = tmp->next;
            tmp->next = curr->next;
                
            curr->next = tmp;
            curr = tmp2;

            std::cout << "im here2 \n";        
            //break;
        }
        //return head;
    }
};
