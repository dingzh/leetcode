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

        stack<TreeNode*> st;
        leftChain(root, st);
        while (!st.empty()) {
            root = st.top();
            st.pop();

            ret.push_back(root->val);

            if (root->right) leftChain(root->right);
        }

        return ret;
    }

    void leftChain(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};
