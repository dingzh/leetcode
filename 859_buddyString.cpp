class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len = A.length();
        if (len != B.length()) return false;
        if (len < 2) return false;
        
        vector<int> diff;
        for (int i = 0; i < len; ++i) {
            if (A[i] != B[i]) diff.push_back(i);
        }
        
        if (diff.size() == 0) return anyDup(A);
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
    
    bool anyDup(const string& A) {
        array<int, 256> cnt;
        cnt.fill(0);
        
        for (char ch : A) {
            if (++cnt[ch] > 1) return true;
        }
        return false;
    }
};
