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
    struct Result {
        int with_cam = 0;
        int covered = 0;
        int not_covered = 0;
    };
public:
    int minCameraCover(TreeNode* root) {
        
        auto res = aux(root);
        return min(res.with_cam, res.covered);
    }
    
    Result aux(TreeNode* node) {
        Result ret;
        if (!node) {
            ret.with_cam = 1;
            return ret;
        }
        
        auto left = aux(node->left);
        auto right = aux(node->right);
        
        int min_left_covered = min(left.with_cam, left.covered);
        int min_right_covered = min(right.with_cam, right.covered);
        
        ret.with_cam = 1 + 
            min(left.not_covered, min_left_covered) + 
            min(right.not_covered, min_right_covered);
        
        ret.covered = min(left.with_cam + min_right_covered, 
                          right.with_cam + min_left_covered );
        ret.not_covered = left.covered + right.covered;
        return ret;
    }
};
