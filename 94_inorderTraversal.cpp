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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        stack<pair<TreeNode*, bool>> st;
        if (root) st.push({root, false});
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            if (top.second) {
                ret.push_back(top.first->val);
            } else {
                root = top.first;
                if(root->right) st.push({root->right, false});
                st.push({root, true});
                if(root->left) st.push({root->left, false});
            }
        }
        return ret;
    }
};
