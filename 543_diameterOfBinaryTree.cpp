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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ret = -1;
        helper(root, ret);
        return ret;
    }

    int helper(TreeNode* root, int& diameter) {
        if (!root) return 0;

        int ltDepth = helper(root->left, diameter);
        int rtDepth = helper(root->right, diameter);

        int diameterThruCurrNode = ltDepth + rtDepth + 1;

        if (diameterThruCurrNode > diameter) diameter = diameterThruCurrNode;

        return ltDepth > rtDepth ? ltDepth + 1 : rtDepth + 1;
    }
};
