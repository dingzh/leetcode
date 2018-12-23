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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {nullptr, nullptr};

        if (root->val > V) {
            auto res = splitBST(root->left, V);
            root->left = res[1];
            return {res[0], root};
        } else {
            auto res = splitBST(root->right, V);
            root->right = res[0];
            return {root, res[1]};
        }
    }
};
