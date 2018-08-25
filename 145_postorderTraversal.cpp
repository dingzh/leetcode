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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;

        stack<TreeNode*> st;
        if(root) highestLeafVisibleFromLeft(root, st);
        while (true) {
            root = st.top();
            st.pop();
            ret.push_back(root->val);

            if (st.empty()) break;
            if (root == st.top()->right) continue;
            if(st.top()->right) highestLeafVisibleFromLeft(st.top()->right, st);
        }
        return ret;
    }

    void highestLeafVisibleFromLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (true) {
            st.push(root);
            if (root->left) {
                root = root->left;
            } else if (root->right) {
                root = root->right;
            } else return;
        }
    }
};
