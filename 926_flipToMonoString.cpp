class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len = S.length();
        if (len <= 1) return 0;
        
        vector<int> end0(len, 0);
        vector<int> end1(len, 0);
        
        if (S[0] == '0') {
            end0[0] = 0;
            end1[0] = 1;
        } else {
            end0[0] = 1;
            end1[0] = 0;
        }
        
        for (int i = 1; i < len; ++i) {
            if (S[i] == '0') {
                end0[i] = end0[i-1];
                end1[i] = min(end0[i-1], end1[i-1]) + 1;
            } else {
                end0[i] = end0[i-1] + 1;
                end1[i] = min(end1[i-1], end0[i-1]);
            }
        }
        
        return min(end0[len-1], end1[len-1]);
    }
};
