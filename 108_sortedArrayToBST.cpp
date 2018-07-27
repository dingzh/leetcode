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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
    
    TreeNode* helper(const vector<int>& nums, int lt, int rt) {
        if (lt == rt) return nullptr;

	int mid = (lt + rt) >> 1;
	TreeNode* left = helper(nums, lt, mid);
	TreeNode* right = helper(nums, mid+1, rt);
	TreeNode* ret = new TreeNode{nums[mid], left, right};

	return ret;
    }
};
