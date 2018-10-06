/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    TreeLinkNode* dummy;
    TreeLinkNode* tail;
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        dummy = new TreeLinkNode(0);
        tail = dummy;

        push(root);
        TreeLinkNode* rightmost = root;
        while (tail != dummy) {
            TreeLinkNode* front = pop();
            if (front->left) push(front->left);
            if (front->right) push(front->right);

            if (front == rightmost) {
                front->next = nullptr;
                rightmost = tail;
            }
        }
    }

    TreeLinkNode* pop() {
        TreeLinkNode* ret = dummy->next;
        dummy->next = ret->next;
        if (ret == tail) tail = dummy;
        return ret;
    }

    void push(TreeLinkNode* node) {
        tail->next = node;
        tail = node;
    }
};
