class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return nums;
        
        int cand_0 = nums[0], cand_1;
        int cnt_0 = 0, cnt_1 = 0;
        int idx = 0;
        for (;idx < size; ++idx) {
            if (nums[idx] == cand_0) ++cnt_0;
            else {
                cand_1 = nums[idx];
                cnt_1 = 1;
                break;
            }
        }
        if (cnt_1 == 0) return {cand_0}; // only one element in this array
        
        ++idx;
        for (; idx < size; ++idx) {
            int num = nums[idx];
            if (num == cand_0) {
                ++cnt_0;
            } else if (num == cand_1) {
                ++cnt_1;
            } else {
                if (cnt_0 == 0) {
                    cnt_0 = 1;
                    cand_0 = num;
                } else if (cnt_1 == 0) {
                    cnt_1 = 1;
                    cand_1 = num;
                } else {
                    --cnt_0;
                    --cnt_1;
                }
            }
        }
        // no possible value more than n/3
        if (!cnt_0 && !cnt_1) return {};
        
        vector<int> ret;
        cnt_0 = cnt_1 = 0;
        for (int num : nums) {
            if (num == cand_0) ++cnt_0;
            else if (num == cand_1) ++cnt_1;
        }
            
        if (cnt_0 > size / 3)  ret.push_back(cand_0);
        if (cnt_1 > size / 3)  ret.push_back(cand_1);
        return ret;
    }
};
