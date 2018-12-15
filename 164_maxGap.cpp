class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;

        int minv, maxv;
        tie(minv, maxv) = minmax_val(nums);
        int bucket_size = max(1, (maxv - minv + 1) / (size - 1));
        int bucket_num =  1 + (maxv - minv ) / bucket_size;
        int max_gap = bucket_size - 1; // max possible value within a bucket

        vector<array<int, 3>> buckets(bucket_num, {0, maxv, minv});
        for (int num : nums) {
            int idx = (num - minv) / bucket_size;
            auto& bucket = buckets[idx];
            bucket[0] = 1;
            bucket[1] = min(bucket[1], num);
            bucket[2] = max(bucket[2], num);
        }

        int prev_max = minv;
        for (auto& vec : buckets) if (vec[0]) {
            int this_min = vec[1];
            int this_max = vec[2];
            max_gap = max(max_gap, this_min - prev_max);
            prev_max = this_max;
        }

        return max_gap;
    }

    pair<int, int> minmax_val(vector<int>& nums) {
        auto minmaxv = minmax_element(begin(nums), end(nums));
        int minv = *minmaxv.first;
        int maxv = *minmaxv.second;

        return {minv, maxv};
    }
};
