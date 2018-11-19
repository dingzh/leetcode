class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        
        combinationAux(0, target, candidates, tmp, ret);
        return ret;
    }
    
    void combinationAux(int start, int target, vector<int>& cand, 
                        vector<int>& tmp, vector<vector<int>>& ret) {
        if (target == 0) { ret.emplace_back(tmp); return ;}
        if (target < cand[start] || start == cand.size()) return ;
        
        int num = cand[start];
        int cnt = target / num;
        
        combinationAux(start + 1, target, cand, tmp, ret);
        for (int i = 1; i <= cnt; ++i) {
            tmp.push_back(num);
            combinationAux(start + 1, target - i * num, cand, tmp, ret);
        }
        
        for (int i = 0; i < cnt; ++i) tmp.pop_back();
    }
};
