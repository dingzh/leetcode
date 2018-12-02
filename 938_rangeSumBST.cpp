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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return dfs(root, L, R);
    }
    
    int dfs(TreeNode* root, int L, int R) {
        if (!root) return 0;
        
        int ret = 0;
        if (root->val <= R) 
            ret += dfs(root->right, L, R);
        
        if (root->val >= L) 
            ret += dfs(root->left, L, R);
        
        if (L <= root->val && root->val <= R)
            ret += root->val;

        return ret;
    }
};
