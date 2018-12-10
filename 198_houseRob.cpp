class Solution {
public:
    int rob(vector<int>& nums) {
        int tminus1 = 0;
        int tminus2 = 0;
        for (int num : nums) {
            int curr = max(tminus1, tminus2 + num);
            tminus2 = tminus1;
            tminus1 = curr;
        }
        return tminus1;
    }
};
