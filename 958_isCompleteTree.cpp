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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        bool end = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto front = q.front(); q.pop();

            if (end && front->left) return false;
            else if (front->left) q.push(front->left);
            else end = true;

            if (end && front->right) return false;
            else if (front->right) q.push(front->right);
            else end = true;
        }

        return true;
    }
};
