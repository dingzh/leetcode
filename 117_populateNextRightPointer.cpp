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
        int currLevel = 1;
        int nextLevel = 0;
        TreeLinkNode *qHead = root, *qTail = root;
        while (qHead != nullptr) {
            if (qHead->left) {++nextLevel; qTail = qTail->next = qHead->left;}
            if (qHead->right) {++nextLevel; qTail = qTail->next = qHead->right;}
            --currLevel;
            if (!currLevel) {
                currLevel = nextLevel; 
                nextLevel = 0;
                TreeLinkNode* tmp = qHead;
                qHead = qHead->next;
                tmp->next = nullptr;
            } else {
                qHead = qHead->next;
            }
        }
    }

};
