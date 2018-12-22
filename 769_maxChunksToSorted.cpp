class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size();
        if (!size) return 0;
        
        auto sorted = arr;
        sort(begin(sorted), end(sorted));
        
        int ret = 0;
        int curr_max = sorted[0];
        for (int i = 0; i < size; ++i) {
            curr_max = max(curr_max, arr[i]);
            if (curr_max <= sorted[i]) ++ret;
        }
        
        return ret;
    }
};
