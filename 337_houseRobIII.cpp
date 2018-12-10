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
    int rob(TreeNode* root) {
        
        int rob, nrob;
        tie(rob, nrob) = robAux(root);
        return max(rob, nrob);
    }
    
    pair<int,int> robAux(TreeNode* root) {
        if (!root) return {0, 0};
        
        int rob1, nrob1, rob2, nrob2;
        tie(rob1, nrob1) = robAux(root->left);
        tie(rob2, nrob2) = robAux(root->right);
        
        return {nrob1 + nrob2 + root->val, max(rob1, nrob1) + max(rob2, nrob2)};
    }
};
