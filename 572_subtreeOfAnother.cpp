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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return s != nullptr && (isSubtree(s->left, t) || isSubtree(s->right, t) || treeComp(s, t));
    }

    bool treeComp(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (s && t) return s->val == t->val && treeComp(s->left, t->left) && treeComp(s->right, t->right);
        return false;
    }
};
