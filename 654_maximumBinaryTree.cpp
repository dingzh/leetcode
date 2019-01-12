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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int size = nums.size();
        
        auto root = aux(nums, 0, size);
        return root;
    }
    
    TreeNode* aux(vector<int>& nums, int begin, int end) {
        if (begin == end) return nullptr;
        
        auto num_begin = nums.begin();
        auto max_pos = max_element(num_begin + begin, num_begin + end);
        
        int pos = distance(num_begin, max_pos);
        
        TreeNode* node = new TreeNode(*max_pos);
        node->left = aux(nums, begin, pos);
        node->right = aux(nums, pos + 1, end);
        return node;
    }
    
    
};
