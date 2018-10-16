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
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        convertAux(root);
        return root;
    }
    
    void convertAux(TreeNode* node) {
        if (!node) return;
        
        convertAux(node->right);
        sum += node->val;
        node->val = sum;
        convertAux(node->left);
    }
};
