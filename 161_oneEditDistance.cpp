class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if (abs(slen - tlen) > 1) return false;
        
        return aux(s, slen, t, tlen, true);
    }
    
    bool aux(const string& s, int slen, const string& t, int tlen, bool edit) {
        if (!edit) return slen == tlen && s.compare(0, slen, t, 0, slen) == 0;
        if (slen == 0 || tlen == 0) return edit && (slen == 1 || tlen == 1);
        
        char a = s[slen-1], b = t[tlen-1];
        if (a == b) return aux(s, slen - 1, t, tlen - 1, true);
        
        if (slen == tlen) { // can only replace
            return aux(s, slen - 1, t, tlen - 1, false);
        } else if (slen > tlen) { // insert or delete
            return aux(s, slen - 1, t, tlen, false);
        } else {
            return aux(s, slen, t, tlen - 1, false);
        }
    }
};
