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
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = 1 << 31;
        findMax(root);
        
        // return maxSum instead of results for recurrsive calls,
        // because findMax only provide internal values, which
        // may or may not be a valid path;
        return maxSum;
    }


    // the subtrees can contribute to the max in two ways
    // 1. a path already completed, which is in global var maxSum
    // 2. half of a path, joinable at its parent
    // however, in the second case, it could also be an empty path,
    // in case it has nothing to provide but negative sum
    int findMax(TreeNode* root) {
        if (!root) return 0;
        int val = root->val;
        int lt = findMax(root->left);
        int rt = findMax(root->right);
        int closedPath = lt + rt + val;
        maxSum = maxSum > closedPath ? maxSum : closedPath;

        int ret = val + max(lt, rt);

        return ret > 0 ? ret : 0;
    }
};
