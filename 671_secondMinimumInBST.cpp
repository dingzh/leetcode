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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> node_queue;
        int min = root->val;
        node_queue.push(root);
        while (!node_queue.empty()) {
            auto front = node_queue.front();
            node_queue.pop();
            if (front->val > min) return front->val;
            else {
                if (front->left) node_queue.push(front->left);
                if (front->right) node_queue.push(front->right);
            }
        }
        return -1;
    }
};
