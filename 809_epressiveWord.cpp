class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        auto s_grps = countGroups(S);
        const auto s_size = s_grps.size();
        
        int ret = 0;
        for (const string& word : words) {
            auto w_grps = countGroups(word);
            
            bool flag = s_size == w_grps.size();
            for(int i = 0; flag && i < s_size; ++i) {
                const auto& wp = w_grps[i];
                const auto& sp = s_grps[i];
                flag = (wp.first == sp.first &&
                 (wp.second == sp.second ||  sp.second > wp.second && sp.second >= 3));
            }
            
            if (flag) ++ret;
        }

        return ret;
    }
    
    vector<pair<char, int>> countGroups(const string& str) {
        vector<pair<char, int>> ret;
        
        if (str.empty()) return ret;
        
        char prev = str[0];
        int cnt = 1;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == prev) {
                ++cnt;
            } else {
                ret.emplace_back(prev, cnt);
                cnt = 1;
                prev = str[i];
            }
        }
        
        ret.emplace_back(prev, cnt);
        return ret;
    }
};
