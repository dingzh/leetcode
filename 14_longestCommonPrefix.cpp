class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return {};
        
        int ret = strs[0].length();
        
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < ret && strs[0][j] == strs[i][j]) ++j;
            ret = j;
        }
        
        return strs[0].substr(0, ret);
    }
};
