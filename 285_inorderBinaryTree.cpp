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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool flag = false;
        return aux(root, p, flag);
    }
    
    TreeNode* aux(TreeNode* root, TreeNode* p, bool& flag) {
        if (root == nullptr) return nullptr;
        
        TreeNode* ret = aux(root->left, p, flag);
        if (ret) return ret;
        if (flag) return root;
        if (root == p) flag = true;
        ret = aux(root->right, p, flag);
        return ret;
    }
};
