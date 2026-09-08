/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        std::map<Node*, Node*> location{};

        location.insert({nullptr,nullptr});

        Node* tmp = head;
        Node  ret = Node(0);
        Node* pret = &ret;

        while( tmp !=nullptr){
            pret->next = new Node(tmp->val);
            location[tmp] = pret->next;
        
            pret->next->random =tmp->random;
            
            pret = pret->next;
            tmp= tmp->next;
        }
        pret = &ret;
        while(pret!=nullptr){
            pret->random = location[pret->random];
            pret = pret->next;
        }



        pret = &ret;
        return ret.next;
        
    }
};
