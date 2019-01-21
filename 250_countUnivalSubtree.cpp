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
    int countUnivalSubtrees(TreeNode* root) {
        if (root) aux(root);
        
        return ret;
    }
    
    pair<int, bool> aux(TreeNode* node) {
        bool flag = true;
        int val = node->val;
        
        if (node->left) {
            auto p = aux(node->left);
            flag = p.second && val == p.first;
        }
        
        if (node->right) {
            auto p = aux(node->right);
            flag = flag && p.second && val == p.first;
        }
        
        if (flag) ++ret;
        return make_pair(node->val, flag);
    }
};
