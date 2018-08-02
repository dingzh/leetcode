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
        return helper(root, p, q);
    }

    TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return nullptr;
        
        if (node == p || node == q) return node;

        auto lt = helper(node->left, p, q);
        auto rt = helper(node->right, p, q);
        if (lt != nullptr && rt != nullptr) return node;

        return lt == nullptr ? rt : lt;
    }
};
