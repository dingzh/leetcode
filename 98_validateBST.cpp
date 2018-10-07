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
    bool isValidBST(TreeNode* root) {

        int prev;
        bool prevset = false;

        stack<TreeNode*> stk;
        pushLeft(stk, root);

        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();

            if (prevset && top->val <= prev) {
                return false;
            }

            prevset = true;
            prev = top->val;

            pushLeft(stk, top->right);
        }

        return true;
    }

    void pushLeft(stack<TreeNode*>& stk, TreeNode* node) {
        while (node) {
            stk.push( node );
            node = node->left;
        }
    }
};
