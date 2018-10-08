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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ret;
        vector<int> levelElm;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode* rightmost = root;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            levelElm.push_back(front->val);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
            
            if (front == rightmost) {
                ret.emplace_back(move(levelElm));
                if (!q.empty()) rightmost = q.back();
            }
        }

        return ret;
    }
};
