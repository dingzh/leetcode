class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,  vector<string>> result;
        for (string& str : strs) {
            string tmp = str;
            sort(begin(tmp), end(tmp));
            // are there duplicate is strs?
            result[tmp].emplace_back(move(str));
        }
        
        vector<vector<string>> ret;
        for (auto& grp : result) {
            ret.emplace_back( move(grp.second));
        }
        return ret;
    }
};
