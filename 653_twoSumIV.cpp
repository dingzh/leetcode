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
    class Iterator {
        stack<TreeNode*> stk;
    public:
        Iterator(TreeNode* root) {
            pushLeft(root);
        }
        
        TreeNode* next() {
            if (stk.empty()) return nullptr;
            TreeNode* top = stk.top();
            stk.pop();
            pushLeft(top->right);
            return top;
        }
        
        void pushLeft(TreeNode* node) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
    };
    
    class RIterator {
        stack<TreeNode* > stk;
    public:
        RIterator(TreeNode* root) {
            pushRight(root);
        }
        
        TreeNode* next() {
            if (stk.empty()) {
                return nullptr;
            }
            TreeNode* top = stk.top();
            stk.pop();
            pushRight(top->left);
            return top;
        }
        
        void pushRight(TreeNode* node) {
            while (node) {
                stk.push(node);
                node = node->right;
            }
        }
    };
public:
    bool findTarget(TreeNode* root, int k) {
         Iterator it(root);
        RIterator rit(root);
        
        TreeNode* lt = it.next(), *rt = rit.next();
        
        while (lt != rt) {
            int val = lt->val + rt->val;
            if (val < k) {
                lt = it.next();
            } else if (val > k) {
                rt = rit.next();
            } else {
                return true;
            }
        }
        return false;
    }
};
