class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();

        if (!size || size < k) return {};
        
        vector<int> ret;
        ret.reserve(size - k + 1);
        list<pair<int, int>> window; // maybe deque is a better choice
        for (int i = 0; i < k - 1; ++i) put(window, nums[i], i, k);

        for (int i = k - 1; i < size; ++i) {
            int res = put(window, nums[i], i, k);
            ret.push_back(res);
        }

        return ret;
    }

    int put(list<pair<int,int>>& window, int num, int idx, int wsize) {
        
        auto it = window.begin();
        if (it != window.end() && it->first <= idx - wsize) window.erase(it);
        
        it = window.begin();
        while (it != window.end() && it->second > num) ++it;
        window.erase(it, window.end());

        window.push_back(make_pair(idx, num));

        return window.front().second;
    }
};
