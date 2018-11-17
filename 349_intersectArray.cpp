class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num_cnt;
        vector<int> ret;
        for (int num : nums1) {
            num_cnt[num] = 1;
        }
        
        for (int num : nums2) {
            if (num_cnt[num]-- == 1) {
                ret.push_back(num);
            }
        }
        return ret;
    }
};
