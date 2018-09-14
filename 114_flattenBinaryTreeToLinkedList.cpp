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
    void flatten(TreeNode* root) {
        if (!root) return ;
        TreeNode dummy(0);
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* curr = &dummy;

        while (!st.empty()) {
            auto top = st.top(); st.pop();

            curr->right = top;
            curr->left = nullptr;
            curr = top;

            if (top->right) st.push(top->right);
            if (top->left) st.push(top->left);
        }
        // curr->right = nullptr;
    }
};
