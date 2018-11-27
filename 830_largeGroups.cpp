class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        // mark end
        S.push_back(0);
        vector<vector<int>> ret;
        
        char prev = 0;
        int cnt = 0, start = 0;
        for (int i = 0; i < S.length(); ++i) {
            char ch = S[i];
            
            if (ch == prev) {
                ++cnt;
            } else {
                if (cnt > 2) {
                    ret.push_back({start, i-1});
                }
                cnt = 1;
                prev = ch;
                start = i;
            }
        }
        return ret;
    }
};
