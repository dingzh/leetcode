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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim(root, L, R, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
    
    TreeNode* trim(TreeNode* root, int L, int R, int boundL, int boundR) {
        if (!root) return root;
        int rootv = root->val;
        
        if (rootv < L) {
            return trim(root->right, L, R, rootv, boundR);
        } else if (rootv > R) {
            return trim(root->left, L, R, boundL, rootv);
        } else {
            if (boundL < L) root->left = trim(root->left, L, R, boundL, rootv);
            if (boundR > R) root->right = trim(root->right, L, R, rootv, boundR);
            return root;
        }
    }
};
