class Solution {
    map<string, bool> cache;
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if (len != s2.length()) return false;

        int comp = s1.compare(s2);
        if (comp == 0) return true;
        
        string key;
        if (comp < 0) {
            key += s1;
            key.push_back(',');
            key += s2; 
        } else {
            key += s2;
            key.push_back(',');
            key += s1; 
        }
        
        if (cache.count(key)) return cache[key];
        
        int diff = 0;
        array<int, 256> char_cnt;
        char_cnt.fill(0);
        
        for (int i = 0; i < len; ++i) {
            if(char_cnt[s1[i]]++ == 0) ++diff;
            if(char_cnt[s2[i]]-- == 1) --diff;
        }
        
        if (diff) {
            cache[key] = false;
            return false;
        }

        for (int i = 1; i < len; ++i) {
            string tmp1 = s1.substr(0, i);
            string tmp2 = s1.substr(i);
            if (isScramble(tmp1, s2.substr(0,i)) && isScramble(tmp2, s2.substr(i)) ||
                isScramble(tmp1, s2.substr(len-i)) && isScramble(tmp2, s2.substr(0, len-i))) {
                cache[key] = true;
                return true;
            }   
        }
        
        cache[key] = false;
        return false;
    }
};
