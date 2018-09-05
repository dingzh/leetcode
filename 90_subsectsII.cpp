class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> numsCount;

        for (auto n : nums) {
            auto res = numsCount.find(n);
            if (res != numsCount.end()) {
                res->second += 1;
            } else {
                numsCount.insert({n, 1});
            }
        }

        vector<vector<int>> ret;
        vector<int> subset;

        helper(numsCount.cbegin(), numsCount, subset, ret);

        return ret;
    }

    void helper(unordered_map<int,int>::const_iterator cit, unordered_map<int,int>& numsCount, vector<int>& subset, vector<vector<int>>& ret) {
        if (cit == numsCount.cend()) {ret.push_back(subset); return;}

        int num = cit->first;
        int cnt = cit->second;
        auto ncit = next(cit);
        helper(ncit, numsCount, subset, ret);
        for (int i = 0; i < cnt; ++i) {
            subset.push_back(num);
            helper(ncit, numsCount, subset, ret);
        }

        for (int i = 0; i < cnt; ++i) subset.pop_back();
    }
};
