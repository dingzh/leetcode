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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ret ;
        if (root1 && root2) { // both not null
            ret = (root1->val == root2->val) && (
                flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)
                || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)
            );
        } else if (root1 || root2) { // one is null
            ret = false;
        } else { // both null
            ret = true;
        }
        return ret;
    }
};
