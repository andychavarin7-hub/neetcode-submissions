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
    bool isSubtreeValid(TreeNode* root, int lowerBound, int upperBound) {
        if (root == nullptr) {
            return true;
        }

        int currVal = root->val;

        //bool ubound = (static_cast<int64_t>(root->val) < upperBound) ? true : false;
       //bool lbound = (static_cast<int64_t>(root->val) > lowerBound) ? true : false;

        if (currVal > lowerBound && currVal < upperBound) {
            return isSubtreeValid(root->left, lowerBound,currVal) && isSubtreeValid(root->right, currVal,upperBound);
        } 
        return false;
    }

    bool isValidBST(TreeNode* root) { return isSubtreeValid(root, INT_MIN, INT_MAX); }
};
