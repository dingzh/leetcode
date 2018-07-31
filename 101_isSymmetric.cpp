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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* lt, TreeNode* rt) {
        bool ret;
        if (lt != nullptr && rt != nullptr) {
            ret = (lt->val == rt->val) && helper(lt->left, rt->right) && helper(lt->right, rt->left);
        } else if (lt == nullptr && rt == nullptr) {
            ret = true;
        } else {
            ret = false;
        }

        return ret;
    }
};
