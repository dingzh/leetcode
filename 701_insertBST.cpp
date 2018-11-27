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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertAux(root, val);
        return root;
    }
    
    void insertAux(TreeNode* &root, int val) {
        if (!root) {
            root = new TreeNode(val);
        } else if (root->val < val) {
            insertAux(root->right, val);
        } else {
            insertAux(root->left, val);
        }
    }
};
