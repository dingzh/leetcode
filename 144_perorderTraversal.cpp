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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        
        vector<int> ret;
        if(root) st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            ret.push_back(root->val);
            if (root->right) st.push(root->right);
            if (root->left) st.push(root->left);
        }
        return ret;
    }
};
