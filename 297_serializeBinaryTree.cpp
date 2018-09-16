/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        ostringstream oss;

        while (cnt) {
            auto front = q.front();
            q.pop();

            if (!front) {
                oss << " null";
                continue;
            }

            --cnt;
            oss << " " << front->val;

            if (front->left) {
                q.push(front->left);
                ++cnt;
            } else {
                q.push(nullptr);
            }

            if (front->right) {
                q.push(front->right);
                ++cnt;
            } else {
                q.push(nullptr);
            }
        }

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);

        TreeNode* dummy = nullptr;
        queue<TreeNode **> q;
        q.push(&dummy);

        int val;
        while (!iss.eof()) {
            auto front = q.front();
            q.pop();

            iss >> val;
            if (iss.fail()) {
                iss.clear();
                iss.ignore(4, ' ');
            } else {
                *front = new TreeNode(val);
                q.push( &( (*front)->left ) );
                q.push( &( (*front)->right ) );
            }
        }

        return dummy;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
