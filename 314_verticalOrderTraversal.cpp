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
    map<int, vector<int>> ret;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<pair<TreeNode*,int>> q;
        q.emplace(root, 0);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* p;
                int col;
                tie(p, col) = q.front();
                q.pop();
                
                ret[col].push_back(p->val);
                if (p->left) q.emplace(p->left, col - 1);
                if (p->right)q.emplace(p->right, col + 1);
            }
        }
        
        vector<vector<int>> vec;
        for (const auto& p : ret) {
            vec.emplace_back(move(p.second));
        }
        return vec;
    }
    
};
