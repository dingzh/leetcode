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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();

        unordered_map<int, int> inorder_root;
        for (int i = 0; i < size; ++i) 
            inorder_root[ inorder[i] ] = i;
     
        return builder(preorder, 0, 0, size, inorder_root);        
    }

    TreeNode*
    builder(vector<int>& preorder, int root_pos, int ibegin,
            int size, unordered_map<int, int>& inorder_root) {

        if (!size) return nullptr;
        int root_val = preorder[root_pos];
        TreeNode* root = new TreeNode(root_val);
        
        int lsize = inorder_root[root_val] - ibegin;
        int rsize = size - lsize -1;

        root->left = builder(preorder, root_pos+1,
                ibegin, lsize, inorder_root);
        root->right = builder(preorder, root_pos+lsize+1,
                inorder_root[root_val] + 1, rsize, inorder_root);

        return root;
    }
    
};
