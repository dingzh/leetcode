class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;

        vector<string> result;
        partitionAux(0, s, result, ret);

        return ret;
    }

    void partitionAux(int offset, string& s, vector<string>& result,
            vector<vector<string>>& ret) {

        int len = s.length();
        if (offset == len) {
            ret.emplace_back(result);
            return ;
        }

        // substr len i
        for (int i = 1; offset + i <= len; ++i ) {
            if (isPalindrome(s, offset, i)) {
                result.emplace_back(s, offset, i);
                partitionAux(offset + i, s, result, ret);
                result.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int offset, int len) {
        int lt = offset, rt = offset + len - 1;
        while (lt < rt) {
            if (s[lt++] != s[rt--]) return false;
        }
        return true;
    }
};
