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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> ret;
        vector<int> path;
        
        helper(root, path, ret);
        
        return ret;
    }

    void helper(TreeNode* root, vector<int>& path, vector<string>& ret) {
        if (!root->left && !root->right) {
            stringstream tmp;
            copy(path.begin(), path.end(), ostream_iterator<int>(tmp, "->"));
            tmp << root->val;
            ret.push_back(tmp.str());
            return ;
        }

        path.push_back(root->val);
        if (root->left) helper(root->left, path, ret);
        if (root->right) helper(root->right, path, ret);
        path.pop_back();
    }
};
