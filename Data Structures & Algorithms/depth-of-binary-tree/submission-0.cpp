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
    int maxDepthCall(TreeNode *root, int depth){

        if(root == nullptr){
            return depth;
        }

        int depthLeft = maxDepthCall(root->left, depth + 1);
        int depthRight = maxDepthCall(root->right, depth + 1);

        return std::max(depthLeft, depthRight);
    }

    int maxDepth(TreeNode* root) {

        /*determine the depth recursively */

        return maxDepthCall(root,0);
        
    }
};
