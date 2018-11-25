class Solution {
    unordered_map<string, bool> cache;
public:
    bool canWin(string s) {
        int len = s.length();
        if (len < 2) return false;
        
        return canWinAux(s);
    }
    
    bool canWinAux(string& s) {
        if (cache.count(s)) return cache[s];
        
        bool ret = false;
        for (int i = 1; i < s.length() && !ret; ++i) {
            if (s[i-1] == '+' && s[i] == '+') {
                s[i-1] = '-';
                s[i] = '-';
                ret = !canWinAux(s);
                s[i-1] = '+';
                s[i] = '+';
            }
        }
        cache[s] = ret;
        return ret;
    }
};
