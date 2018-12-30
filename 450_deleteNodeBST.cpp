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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key); 
            return root;
        } else {
            if (!root->left && !root->right) {
                // delete root;
                return nullptr;
            } else if (root->right && root->left) {
                int maxkey = getMax(root->left);
                root->left = deleteNode(root->left, maxkey);
                root->val = maxkey;
                return root;
            } else {
                return root->left ? root->left : root->right;
            }
        }
    }
    
    int getMax(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
};
