class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size());
    }

    int merge(vector<int>& nums, int lt, int rt) {
        int size = rt - lt;
        if (size < 2) return 0;

        int mid = lt + (size >> 1);
        int ret = merge(nums, lt, mid);
        ret    += merge(nums, mid, rt);
        
        // counting reverse pair between two parts
        int lp = lt, rp = mid;
        while (lp < mid && rp < rt) {
            // there is this naghsty overflow problem
            long long ltmp = nums[lp];
            long long rtmp = nums[rp];
            if (ltmp > (rtmp << 1)) { // important reverse pair
                ret += mid - lp;
                ++rp;
            } else {
                ++lp;
            }
        }
        
        // another pass for merging
        lp = lt; rp = mid;
        vector<int> tmp;
        tmp.reserve(size);
        while (lp < mid && rp < rt) {
            if (nums[lp] > nums[rp]) {
                tmp.push_back(nums[rp++]);
            } else {
              tmp.push_back(nums[lp++]);
            }
        }
        // whichever has leftovers
        copy(nums.begin() + lp, nums.begin() + mid, back_inserter(tmp));
        copy(nums.begin() + rp, nums.begin() + rt, back_inserter(tmp));

        // copy back
        copy(tmp.begin(), tmp.end(), nums.begin() + lt);

        return ret;
    }
};
