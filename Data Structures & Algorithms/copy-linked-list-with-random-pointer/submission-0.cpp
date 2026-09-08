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
        Node* pret = nullptr;

        while( tmp !=nullptr){
            //pret->next = new Node(tmp->val);
            pret =new Node(tmp->val);
            location[tmp] =pret;
            tmp= tmp->next;
        }
        pret = head;
        while(pret!=nullptr){
            Node *copy = location[pret];
            copy->next = location[pret->next];
            copy->random = location[pret->random];
            pret= pret->next;
        }
        return location[head];
        
    }
};
