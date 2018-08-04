class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> lookup_s(128, 0);
        vector<char> lookup_t(128, 0);
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            if (lookup_s[s[i]] == t[i]) continue;

            if (lookup_s[s[i]] || lookup_t[t[i]]) {
                return false;
            } else {
                lookup_s[s[i]] = t[i];
                lookup_t[t[i]] = 1;
            }
        }
        return true;
    }
};
