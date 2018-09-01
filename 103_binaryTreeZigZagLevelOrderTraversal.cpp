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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ret;
        vector<int> levelElms;
        queue<TreeNode*> q;
        q.push(root);

        int currLevelCnt = 1, nextLevelCnt = 0;
        int reverseFlag = 0;

        while (!q.empty()) {
            if (currLevelCnt) {
                auto top = q.front();
                q.pop();
                --currLevelCnt;
                if (top->left) {++nextLevelCnt; q.push(top->left);}
                if (top->right) {++nextLevelCnt; q.push(top->right); }
                levelElms.push_back(top->val);
            } else {
                if (reverseFlag) reverse(levelElms.begin(), levelElms.end());
                ret.push_back(move(levelElms));
                reverseFlag ^= 1;
                currLevelCnt = nextLevelCnt;
                nextLevelCnt = 0;
            }
        }

        if (reverseFlag) reverse(levelElms.begin(), levelElms.end());
        if (!levelElms.empty()) ret.push_back(move(levelElms));

        return ret;
    }
};
