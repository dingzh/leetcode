class BitTree {
    struct BitNode {
        BitNode* left;
        BitNode* right;
        BitNode():left(nullptr), right(nullptr) {}
    };
    BitNode root;
public:
    BitTree(vector<int>& nums) {
        for (int num : nums) {
            int mask = 1 << 30;
            BitNode* p = &root;
            while (mask) {
                int bit = num & mask;
                mask = mask >> 1;

                if (bit) {
                    if (!p->right) p->right = new BitNode();
                    p = p->right;
                } else {
                    if (!p->left) p->left = new BitNode();
                    p = p->left;
                }
            }
        }
    }

    int maxXOR(int num) {
        int ret = 0;
        int mask = 1 << 30;
        BitNode* p = &root;
        while (mask) {
            int bit = num & mask;
            if (bit && p->left) { // bit is one
                ret |= mask; // set this bit to one
                p = p->left;
            } else if (!bit && p->right) {
                ret |= mask;
                p = p->right;
            } else {
                ret &= (~mask); // set this bit to zero
                p = p->left ? p->left : p->right;
            }
            mask = mask >> 1;
        }

        return ret;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BitTree bt(nums);
        int ret = 0;
        for(int num : nums) {
            ret = max( ret, bt.maxXOR( num ) );
        }

        return ret;
    }
};
