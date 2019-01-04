class Solution {
    // map<string, int> memo;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return aux(price, special, 0, needs);
    }
    
    int aux(vector<int>& price, vector<vector<int>>& special, int start, const vector<int>& needs) {
        int ret = 0;
        const int size = needs.size();
        for (int i = 0; i < size; ++i) {
            ret += price[i] * needs[i];
        }
        
        // if no available offer
        if (start >= special.size()) return ret;

        const auto& offer = special[start];
        ret = min(ret, aux(price, special, start + 1, needs)); // skip this offer
        for (int cnt = 1; ;++cnt) {
            vector<int> new_needs;
            for (int i = 0; i < size; ++i) {
                int diff = needs[i] - cnt * offer[i];
                if (diff >= 0)  new_needs.push_back(diff); 
            }
            
            if (new_needs.size() != size) break;
            ret = min(ret, 
                      cnt * offer.back() + aux(price, special, start + 1, new_needs));
        }

        return ret;
    }
};
