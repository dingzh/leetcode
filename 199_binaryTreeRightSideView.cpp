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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<int> ret;
        q.push(root);
        int currLevelNode = 1, nextLevelNode = 0;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            --currLevelNode;
            if (top->left) {
                ++nextLevelNode; q.push(top->left);
            }
            if (top->right) {
                ++nextLevelNode; q.push(top->right);
            }

            if (!currLevelNode) {
                ret.push_back(top->val);
                currLevelNode = nextLevelNode;
                nextLevelNode = 0;
            }
        }
        
        return ret;
    }
};
