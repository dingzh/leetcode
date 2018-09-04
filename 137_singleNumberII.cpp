class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {0};
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if (num & (1 << i)) ++cnt[i];
            }
        }
        
        int ret;
        for (int i = 31; i > 0; --i) {
            ret += cnt[i] % 3;
            ret =<< 1;
        }

        ret += cnt[0] % 3;
        return ret;
    }
};
