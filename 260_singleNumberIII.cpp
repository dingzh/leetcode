class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorReduce = 0;
        for (auto num : nums) xorReduce ^= num;
        
        int lastSetBit = (xorReduce & (xorReduce - 1)) ^ xorReduce;
        
        int ret1 = 0, ret2 = 0;
        
        for (auto num : nums) {
            if (num & lastSetBit) ret1 ^= num;
            else ret2 ^= num;
        }

        return {ret1, ret2};
    }
};
