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
    int ret = 0;
public:
    int distributeCoins(TreeNode* root) {
        helper(root);
        return ret;
    }
    
    int helper(TreeNode* node) {
        if (!node) return 0;
        
        int left = helper(node->left);
        int right = helper(node->right);
        
        ret += abs(left) + abs(right);
        return left + right + node->val - 1;
    }
};
