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
    bool isBalanced(TreeNode* root) {
        return helper(root) >= 0;
    }

    int helper(TreeNode* node) {
        if (!node) return 0;
        int lt = helper(node->left);
        int rt = helper(node->right);

        if (abs(lt - rt) < 2) return max(lt, rt) + 1;
        else return 1u << 31;
    }
};
