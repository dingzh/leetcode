class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        vector<int> days(N, 0);
        // on which day flower on position i bloom
        for (int i = 0; i < N; ++i) {
            days[ flowers[i] - 1 ] = i + 1;
        }

        int first_day = numeric_limits<int>::max();
        int left = 0, right = k + 1;
        while (right < N) {
            int bloom_after = max(days[left], days[right]);
            int idx = left + 1;
            for (; idx < right && days[idx] > bloom_after; ++idx) { }
            if (idx == right) first_day = min(first_day, bloom_after);
            left = idx;
            right = left + k + 1;
        }

        return first_day == numeric_limits<int>::max() ? -1 : first_day;
    }
};
