class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        auto sum = accumulate(candidates.begin(), candidates.end(), 0);
        if (sum < target || candidates.size() < 1) return {};

        sort(candidates.begin(), candidates.end());

        vector<bool> chosen(candidates.size(), false);
        vector<vector<int>> ret;

        helper(0, 0, sum, target, candidates, chosen, ret);

        return ret;
    }

    void helper(int l, int k, int r, int target, vector<int>& candidates, vector<bool>& chosen, vector<vector<int>>& ret) {
        chosen[k] = true;
        auto kcand = candidates[k];
        if (l + kcand == target ) {
            vector<int> tmp;
            for (int i = 0; i <= k; ++i) {
                if (chosen[i]) tmp.push_back(candidates[i]);
            }
            ret.push_back(move(tmp));
        } else if(k + 1 < candidates.size()) {
            if (l + kcand + candidates[k+1] <= target) helper(l + kcand, k + 1, r - kcand, target, candidates,     chosen, ret);
            
            chosen[k] = false;
            int next = k + 1;
            while (next < candidates.size() && candidates[next] == kcand) {chosen[next++] = false; r -= kcand;}
            
            if (l + r - kcand >= target && l + candidates[next] <= target) {
                helper(l, next, r - kcand, target, candidates, chosen, ret);
            }
        }
    }
};
