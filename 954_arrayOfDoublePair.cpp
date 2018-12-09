class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> int_cnt;
        for (int num : A) int_cnt[num]++;
        
        auto comp = [](int a, int b) { return abs(a) < abs(b);};
        sort(begin(A), end(A), comp);
        
        for (int num : A) {
            if (int_cnt[num] == 0) continue;
            
            --int_cnt[num];
            if (int_cnt[2 * num]-- == 0) return false;
        }
        return true;
    }
};
