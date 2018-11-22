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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = getLeaf(root1);
        vector<int> leaf2 = getLeaf(root2);
        
        return identical(leaf1, leaf2);
    }
    
    vector<int> getLeaf(TreeNode* root) {
        vector<int> ret;
        
        if (!root) return ret;
        
        // dfs
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            
            if (curr->left == nullptr && curr->right == nullptr) {
                ret.push_back(curr->val);
                continue;
            } 
            if (curr->left != nullptr) {
                stk.push(curr->left);
            }
            if (curr->right != nullptr) {
                stk.push(curr->right);
            }
        }
        return ret;
    }
    
    bool identical(vector<int>& vec1, vector<int>& vec2) {
        int size = vec1.size();
        if (size != vec2.size()) return false;
        
        for (int i = 0; i < size; ++i) {
            if (vec1[i] != vec2[i]) return false;
        }
        
        return true;
    }
};
