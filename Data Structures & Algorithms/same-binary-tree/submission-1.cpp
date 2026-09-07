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
        /*go level by level using a BFS like search */

        std::queue<TreeNode*> leftTree;
        std::queue<TreeNode*> rightTree;

        leftTree.push(p);
        rightTree.push(q);

        while (!(leftTree.empty() && rightTree.empty())){
            TreeNode *tmpA = nullptr;
            TreeNode *tmpB = nullptr;

            if(!leftTree.empty()){
                tmpA = leftTree.front();
                leftTree.pop();
            }

            if(!rightTree.empty()){
                tmpB = rightTree.front();
                rightTree.pop();
            }

            if( tmpA == nullptr && tmpB == nullptr){
                /*continue nothing to do here */
            } else if (tmpA != nullptr && tmpB != nullptr){
                if(tmpA->val == tmpB->val){
                    leftTree.push(tmpA->left);
                    leftTree.push(tmpA->right);
                    rightTree.push(tmpB->left);
                    rightTree.push(tmpB->right);
                } else {
                    return false;
                }

            } else {
                return false;
            }
           
        }


        
        return true;
    }
};
