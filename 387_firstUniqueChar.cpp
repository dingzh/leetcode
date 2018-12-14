class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<char, int>> first_seen;
        array<int, 26> counter;
        for (int& cnt : counter) cnt = 0;

        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int ch = s[i];
            int idx = ch - 'a';
            if (counter[idx]++ == 0) {
                first_seen.emplace_back(ch, i);
            }
        }
        for (auto& ch_idx : first_seen) {
            int idx = ch_idx.first - 'a';
            if (counter[idx] == 1) return ch_idx.second;
        }
        return -1;
    }
};
