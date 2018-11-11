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
    int countNodes(TreeNode* root) {
        int ret = 0;
        int h = height( root );

        while (h > 0) {
            ++ret; // root is not null
            int hr = height( root->right );
            if (h - 1 == hr) {
                ret += ( 1 << (h-1) ) - 1;
                root = root->right;
                h = hr;
            } else { // right child is full
                ret += ( 1 << hr ) - 1;
                root = root->left;
                h = h - 1;
            }
        }

        return ret;
    }

    int height(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
};
