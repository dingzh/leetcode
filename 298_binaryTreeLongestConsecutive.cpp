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
    int longestConsecutive(TreeNode* root) {
        int max_length = 0;
        if (!root) return 0;
        consecutiveAux(root, max_length);
        return max_length;
    }

    int consecutiveAux(TreeNode* root, int& max_len) {
        // check before calling
        // return max len starting for this root
        // modify max_len too
        
        int lt = 0, rt = 0, ret = 0;
        if (root->left) {
            lt = consecutiveAux(root->left, max_len);
            if (root->left->val == root->val + 1) {
                ret = lt;
            }
        }
        if (root->right) {
            rt = consecutiveAux(root->right, max_len);
            if (root->right->val == root->val + 1) {
                ret = max(rt, ret);
            }
        }
        
        ret += 1;
        max_len = max(max_len, ret);

        return ret;
    }
};
