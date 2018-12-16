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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ret = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            ++ret;
            int size = q.size();
            while(size--) {
                auto p = q.front();
                q.pop();
                bool flag = true;
                if (p->left) {
                    flag = false;
                    q.push(p->left);
                }
                if (p->right) {
                    flag = false;
                    q.push(p->right);
                }
                if (flag) return ret;
            }
        }
        return ret;
    }
};
