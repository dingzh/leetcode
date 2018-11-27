class Solution {
    unordered_map<unsigned long, bool> cache;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        // base for recursion
        unsigned long key = len1;
        key = (key << 32) + len2;

        cache[key] = true;
        
        return isInterleaveAux(s1, s2, s3, 0, 0, 0);
    }
    
    bool isInterleaveAux(string& s1, string& s2, string& s3, int idx1, int idx2, int idx3) {

        unsigned long key = idx1;
        key = (key << 32) + idx2;
        if (cache.count(key)) return cache[key];
        
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        
        bool ret = false;

        if (idx1 < len1 && s1[idx1] == s3[idx3]) {
            ret = isInterleaveAux(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
        }

        if (!ret && idx2 < len2 && s2[idx2] == s3[idx3]) {
            ret = isInterleaveAux(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
        }
        
        cache[key] = ret;
        return ret;
    }
};
