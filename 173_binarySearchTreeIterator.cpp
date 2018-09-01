/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {

    stack<TreeNode*> st;

    void pushLeftChain(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        if (root) pushLeftChain(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto top = st.top();
        st.pop();
        
        if (top->right) pushLeftChain(top->right);

        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
