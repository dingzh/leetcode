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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        stack<TreeNode*> path_to_target;
        bool found = findPath(root, target, path_to_target);
        if (!found) return {};
        
        vector<int> ret;
        distanceAux(target, K, ret);

        TreeNode* prev = path_to_target.top();
        path_to_target.pop();
        int dist = K-1;
        while (dist >= 0 && !path_to_target.empty()) {
            TreeNode* node = path_to_target.top();
            path_to_target.pop();
            if (dist == 0) ret.push_back(node->val);
            --dist;
            TreeNode* offpath = node->left == prev ? node->right :node->left;
            distanceAux(offpath, dist, ret);
            prev = node;
        }

        return ret;
    }

    void distanceAux(TreeNode* root, int K, vector<int>& ret) {
        if (!root) return;
        if (K == 0) ret.push_back(root->val);
        distanceAux(root->left, K-1, ret);
        distanceAux(root->right, K-1,ret);
    }

    bool findPath(TreeNode* node, TreeNode* target, stack<TreeNode*>& path) {
        if (!node) return false;
        path.push(node);
        if (node == target) return true;

        if (findPath(node->left, target, path)) return true;
        if (findPath(node->right, target, path)) return true;
        path.pop();
        return false;
    }
};
