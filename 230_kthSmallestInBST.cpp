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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int cnt = 0;
        int ret;
        // no need to check root
        pushLeftChain(root, st);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            ++cnt;
            if (cnt == k) return top->val;
            if (top->right) pushLeftChain(top->right);
        }

        // if not return yet, k > size of BST
        return 0;
    }

    void pushLeftChain(TreeNode* root, stack<TreeNode*>& st) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
};
