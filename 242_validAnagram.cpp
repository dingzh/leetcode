class Solution {
public:
    bool isAnagram(string s, string t) {
        int* ch_cnt = new int[256];
        fill(ch_cnt, ch_cnt+256, 0);

        for (char ch : s) { ++ch_cnt[ch]; }
        for (char ch : t) { --ch_cnt[ch]; }

        for (int i = 0; i < 256; ++i) {
            if (ch_cnt[i]) return false;
        }
        
        delete [] ch_cnt;

        return true;
    }
};
