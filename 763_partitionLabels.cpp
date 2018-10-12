class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        int last_seen[256] = {0};
        for (int idx = 0; idx < len; ++idx) last_seen[S[idx]] = idx;

        vector<int> ret;
        int begin = 0, end = -1;
        for (int idx = 0; idx < len; ++idx) {
            end = max(end, last_seen[ S[idx] ]);
            if (end == idx) {
                ret.push_back(end - begin + 1);
                begin = idx + 1;
            }
        }
        return ret;
    }
};
