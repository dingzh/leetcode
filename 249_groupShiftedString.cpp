class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> umap;
        
        for (auto& str : strings) if (!str.empty()) {
            string str_h;
            char base = str[0];
            for (char ch : str) {
                str_h.push_back((ch - base + 26) % 26);
            }
            umap[str_h].emplace_back(move(str));
        }
        
        vector<vector<string>> ret;
        for (decltype(umap)::value_type p : umap) {
            ret.emplace_back(move(p.second));
        }
        
        return ret;
    }
};
