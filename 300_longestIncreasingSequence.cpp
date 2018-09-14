class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;

        vector<int> minSeqEnd;
        //constexpr int minInt = 1 << 31;
        //minSeqEnd.push_back(minInt);

        for (int i = 0; i < size; ++i) {
            int idx = leftGreaterEqual(minSeqEnd, nums[i]);
            if (idx == minSeqEnd.size()) minSeqEnd.emplace_back(nums[i]);
            else minSeqEnd[idx] = nums[i];
        }

        return minSeqEnd.size();
    }

    // return the index where the first element is not smaller that target
    // if such element doen not exist, return 1 past end;
    int leftGreaterEqual(const vector<int>& seq, int target) {
        int lt = 0, rt = seq.size();

        while (lt < rt) {
            int mid = (lt + rt) >> 1;
            if (seq[mid] >= target) rt = mid;
            else lt = mid + 1;
        }
        return rt;
    }
};
