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

        /* I can reduce this down to a pair search style */
        std::queue<std::pair<TreeNode*, TreeNode*>> treeComp;
        treeComp.push({p, q});
        while (!treeComp.empty()) {
            auto [tmpA, tmpB] = treeComp.front();
            treeComp.pop();

            if (tmpA == nullptr && tmpB == nullptr) {
                /*continue nothing to do here */
            } else if (tmpA != nullptr && tmpB != nullptr) {
                if (tmpA->val != tmpB->val) {
                    return false;
                }
                treeComp.push({tmpA->left,tmpB->left});
                treeComp.push({tmpA->right,tmpB->right});
            } else {
                return false;
            }
        }

        return true;
    };

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*another queue based search here */
        bool subtree = false;
        std::queue<TreeNode*> treeSearch{};

        treeSearch.push(root);
        while (!treeSearch.empty()) {
            TreeNode* tmp = treeSearch.front();
            treeSearch.pop();

            if(tmp != nullptr && subRoot!=nullptr){
                if(tmp->val == subRoot->val && !subtree){
                    subtree = isSameTree(tmp,subRoot);
                } else {
                    //continue;
                }
                treeSearch.push(tmp->left);
                treeSearch.push(tmp->right);
            }

        }
        return subtree;
    }
}
;
