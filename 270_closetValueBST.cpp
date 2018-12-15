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
    int closestValue(TreeNode* root, double target) {
        assert(root);
        int ret = root->val;
        while (root) {
            int val = root->val;
            if (fabs(target - val) < fabs(target - ret)) ret = val;
            if (val > target) {
                root = root->left;
            } else if (val < target) {
                root = root->right;
            } else {
                return val;
            }
        }
        return ret;
    }
};
