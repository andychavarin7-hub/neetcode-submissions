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
    TreeNode* invertTree(TreeNode* root) {

        std::stack<TreeNode*> processList{};
        processList.push(root);

        while(!processList.empty()){

            TreeNode *tmp = processList.top();
            processList.pop();

            if(tmp !=nullptr){
                /*swap and move down */
                std::swap(tmp->left, tmp->right);
                processList.push(tmp->left);
                processList.push(tmp->right);
            }
        }


        return root;
        
    }
};
