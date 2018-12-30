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
        stringstream out;
        if (!root) return out.str();
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            auto top = stk.top(); stk.pop();
            out << top->val << ' ';
            if (top->right) stk.push(top->right);
            if (top->left)  stk.push(top->left);
        }
        
        return out.str();
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> nums;
        int val;
        ss >> val;
        while (!ss.fail()) {
            nums.push_back(val);
            ss >> val;
        }
        if (nums.empty()) return nullptr;

        int index = 0;

        return deserializeAux(nums, index, 
                numeric_limits<int>::min(), numeric_limits<int>::max());
    }
    
    TreeNode* deserializeAux(vector<int>& nums, int& index, int lt, int rt) {
        if (index >= nums.size()) return nullptr;
        
        int val = nums[index];
        if (lt <= val && rt >= val) {
            ++index;
            TreeNode* root = new TreeNode(val);
            root->left = deserializeAux(nums, index, lt, val);
            root->right =deserializeAux(nums, index, val, rt);
            return root;
        } else {
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

