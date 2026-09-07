/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        std::stack<std::pair<TreeNode*,TreeNode*>> treeTraveseral{};

        treeTraveseral.push({p,q});

        while(!treeTraveseral.empty()){

            auto [tmpA, tmpB] = treeTraveseral.top();
            treeTraveseral.pop();

            if(tmpA != nullptr && tmpB!=nullptr){
                if(tmpA->val != tmpB->val){
                    return false;
                }
                /*else traverse the tree downward */
                treeTraveseral.push({tmpA->left,tmpB->left});
                treeTraveseral.push({tmpA->right,tmpB->right});

            } else if ( tmpA ==nullptr && tmpB == nullptr){
                /*fine if both point to nullptr*/
            } 
            else {
                return false;
            }

        }
        
        return true;
    }
};
