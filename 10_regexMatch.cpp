class Solution {
    unordered_map<int, bool> cache;
public:
    bool isMatch(string s, string p) {
        return isMatchAux(s, p, 0, 0);
    }
    
    bool isMatchAux(string& s, string& p, int sidx, int pidx) {
        if (pidx < 0 || sidx < 0) return false;
        int plen = p.length(), slen = s.length();
        int key = sidx * plen + pidx;
        
        if (cache.count(key)) return cache[key];
        
        if (sidx == slen) return isNullTrail(p, pidx);
        if (pidx == plen) return sidx == slen;
        
        bool ret = false;
        bool empty = pidx + 1 < plen && p[pidx+1] == '*';
        bool match = s[sidx] == p[pidx] || p[pidx] == '.';
        
        if (empty && match) {
            ret = isMatchAux(s, p, sidx, pidx + 2) || isMatchAux(s, p, sidx + 1, pidx);
        } else if (empty && !match) {
            ret = isMatchAux(s, p, sidx, pidx + 2);
        } else if (!empty && match) {
            ret = isMatchAux(s, p, sidx + 1, pidx + 1);
        } else { // !empty() && !match
            ret = false;
        }
        
        cache[key] = ret;
        return ret;
    }
    
    bool isNullTrail(string& p, int idx) {
        int plen = p.length();
        if (idx < plen && p[idx] == '*') ++ idx;
        
        while (idx + 1 < plen) {
            if (p[idx + 1] == '*') idx += 2;
            else return false;
        }
            
        return idx == plen;
    }
};
