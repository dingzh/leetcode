class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> card_cnt;
        for (auto k : deck) ++card_cnt[k];
        
        int gcd_curr = card_cnt.begin()->second;
        for (auto& p : card_cnt) {
            gcd_curr = __gcd(gcd_curr, p.second);
        }
        
        return gcd_curr > 1;
    }
};
