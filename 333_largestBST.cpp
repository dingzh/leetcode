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
    struct BSTInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int treeSize;
        BSTInfo() : isBST(false) {}
    };
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        int ret = 1;
        BSTSubtree(root, ret);
        return ret;
    }
    
    BSTInfo BSTSubtree(TreeNode* root, int& ret) {
        BSTInfo bsti;
        int rval = root->val;
        
        if (root->left && root->right) {
            auto bsti_left = BSTSubtree(root->left, ret);
            auto bsti_right = BSTSubtree(root->right, ret);
            if (bsti_left.isBST &&  bsti_right.isBST 
                && bsti_left.maxVal < rval && bsti_right.minVal > rval) {
                bsti.isBST = true;
                bsti.maxVal = bsti_right.maxVal;
                bsti.minVal = bsti_left.minVal;
                bsti.treeSize = bsti_left.treeSize + bsti_right.treeSize + 1;
                ret = max(ret, bsti.treeSize);
            }
            
        } else if (root->left) {
            auto bsti_left = BSTSubtree(root->left, ret);
            if (bsti_left.isBST && bsti_left.maxVal < rval) {
                bsti.isBST = true;
                bsti.maxVal = rval;
                bsti.minVal = bsti_left.minVal;
                bsti.treeSize = bsti_left.treeSize + 1;
                ret = max(ret, bsti.treeSize);
            }
        } else if (root->right) {
            auto bsti_right = BSTSubtree(root->right, ret);
            if (bsti_right.isBST && bsti_right.minVal > rval) {
                bsti.isBST = true;
                bsti.maxVal = bsti_right.maxVal;
                bsti.minVal = rval;
                bsti.treeSize = bsti_right.treeSize + 1;
                ret = max(ret, bsti.treeSize);
            }
        } else {
            bsti.isBST = true;
            bsti.minVal = rval;
            bsti.maxVal = rval;
            bsti.treeSize = 1;
        }
        return bsti;
    }
};
