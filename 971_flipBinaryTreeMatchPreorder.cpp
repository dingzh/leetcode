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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        int idx = 0;
        vector<int> ret;
        
        bool res = aux(root, voyage, idx, ret);
        if (!res || idx != voyage.size()) {
            ret.clear();
            ret.push_back(-1);
        }
        
        return ret;
    }
    
    bool aux(TreeNode* root, vector<int>& voyage, int& idx, vector<int>& ret) {
        if (!root) return true;
        int size = voyage.size();
        if (idx >= size || root->val != voyage[idx]) return false;
        ++idx;
        
        if (idx >= size && (root->left || root->right)) return false;
        if (root->left && root->right && root->right->val == voyage[idx]) {
            ret.push_back(root->val);
            swap(root->left, root->right);
        }
        
        bool res = aux(root->left, voyage, idx, ret);
        if (!res) return false;
        res = aux(root->right, voyage, idx, ret);
        return res;
    }
};
