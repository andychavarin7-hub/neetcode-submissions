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
    int maxDepthCall(TreeNode *root, int depth, bool & isBalance){

        if(root == nullptr){
            return depth;
        }

        int depthLeft = maxDepthCall(root->left, depth + 1 , isBalance);
        int depthRight = maxDepthCall(root->right, depth + 1, isBalance);

        if( (depthLeft - depthRight) > 1 || (depthRight - depthLeft) >1 ){
            isBalance = false;
        }

        return std::max(depthLeft, depthRight);
    }




    bool isBalanced(TreeNode* root) {
        bool isBalance =true;
        int depth = maxDepthCall(root,0,isBalance);


        return isBalance;
    }
};
