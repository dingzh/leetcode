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
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = nullptr, *node2 = nullptr, *prev = nullptr;

        stack<TreeNode*> stk;
        pushLeft(root, stk);

        while (!stk.empty()) {
            auto curr = stk.top(); 
            stk.pop();
            if (prev && prev->val > curr->val) {
                if (node1 == nullptr) {
                    node1 = prev;
                    node2 = curr;
                } else {
                    node2 = curr;
                    break;
                }
            }
            pushLeft(curr->right, stk);
            prev = curr;
        }

        if (node1 != nullptr) {
            swap(node1->val, node2->val);
        }
    }

    void pushLeft(TreeNode* root, stack<TreeNode*>& stk) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }
};
