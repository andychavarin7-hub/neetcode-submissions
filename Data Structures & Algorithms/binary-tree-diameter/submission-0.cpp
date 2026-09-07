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

    int maxDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        /*compute realtive depth down one side and down the other side */
        int rightDepth = maxDepth(root->right);
        int leftDepth = maxDepth(root->left);
        return 1+ std::max(rightDepth,leftDepth);

    }

    int maxDiameter(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftDepth =  maxDepth(root->left);
        int righDepth = maxDepth(root->right);

        int leftMax = maxDiameter(root->left);
        int rightMax = maxDiameter(root->right);

        int max = std::max(leftDepth +righDepth, leftMax);
       
        return std::max(rightMax,max);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        return maxDiameter(root);
    }
};
