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

    int maxDepth(TreeNode* root) {

        /*determine the depth recursively */
        /* can I do this non recursively ??*/
        int depthMax = 0;
        std::stack<std::pair<TreeNode*, int>> depthCheck{};
        depthCheck.push({root,0});

        while( !depthCheck.empty()){
            auto [node, depth] = depthCheck.top();
            depthCheck.pop();
            if(node !=nullptr){
                depthCheck.push({node->left,depth+1});
                depthCheck.push({node->right,depth+1});
            }

            depthMax = std::max(depthMax, depth);

        }
        return depthMax;
    }
};
