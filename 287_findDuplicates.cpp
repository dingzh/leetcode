class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int  n = nums.size() -1, lt = 1, rt = n;

        while (lt < rt) {
            int mid = (lt + rt) >> 1;
            int cnt = 0;
            for (auto num : nums) {
                if (num > mid) ++cnt;
            }
            if (cnt > n - mid) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return lt;
    }
};
