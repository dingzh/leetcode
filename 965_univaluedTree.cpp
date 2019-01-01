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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        return aux(root->left, val) && aux(root->right, val);
    }
    
    bool aux(TreeNode* root, int val) {
        return !root || root->val == val && aux(root->left, val) && aux(root->right, val);
    }
};
