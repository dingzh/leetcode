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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return {};
        
        vector<vector<vector<TreeNode*>>> dp(n+1, vector<vector<TreeNode*>>(n+1, vector<TreeNode*>()));
        vector<TreeNode*> dummy = {nullptr} ;
        
        for (int i = 1; i <= n; ++i) dp[i][i].push_back( new TreeNode(i) );
        
        for (int len = 2; len <= n; ++len) {
            for (int lt = 1; lt + len - 1 <= n; ++lt) {
                int rt = lt + len - 1;
                
                auto& res = dp[lt][rt];
                for (int mid = lt; mid <= rt; ++mid) {
                    const auto& lnodes = (mid-1 >= lt) ? dp[lt][mid-1] : dummy;
                    const auto& rnodes = (mid+1 <= rt) ? dp[mid+1][rt] : dummy;
                    
                    for (auto lnode : lnodes) {
                        for (auto rnode : rnodes) {
                            auto node = new TreeNode(mid);
                            node->left = lnode;
                            node->right = rnode;
                            res.push_back(node);
                        }
                    }
                }
            }
        }
        
        return dp[1][n];
    }
};
