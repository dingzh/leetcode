/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val, qval = q->val;
        int lval = min(pval, qval);
        int rval = max(pval, qval);

        auto ret = root;
        while (true) {
            if (ret->val < lval) ret = ret->right;
            else if (rval < ret->val) ret = ret->left;
            else { break; }
        }

        return ret;
    }
};
