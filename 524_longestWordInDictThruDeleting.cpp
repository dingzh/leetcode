class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = 0;
        string* res = nullptr;

        for (string& str : d) {
            if (str.length() < len) continue;
            if ( isSubseq(s, str) && 
               (len < str.length() || len == str.length() && res->compare(str) > 0 ) ) {
                    len = str.length();
                    res = &str;
            }
        }

        // incase no result
        if (!res) return "";
        else return *res;
    }
    
    // check if str is a subsequence of S
    bool isSubseq(string& S, string& s) {
        int s_len = s.length(), S_len = S.length();
        if (s_len > S_len) return false;

        int idx = 0;
        for (char ch : s) {
            while (idx < S_len && S[idx] != ch) ++idx;
            if (idx == S_len) return false;
            ++idx;
        }
        return true;
    }
};
