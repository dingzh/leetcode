/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        TreeLinkNode* levelStart = root;
        while (levelStart->left) {
            TreeLinkNode* it = levelStart;
            do {
                it->left->next = it->right;
                if (it->next) it->right->next = it->next->left;
                it = it->next;
            } while (it);
            
            levelStart = levelStart->left;
        }
    }
};
