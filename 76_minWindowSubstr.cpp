class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0 || s.length() == 0) return "";
        unordered_map<char, int> char_cnt;
        unordered_set<char> t_set;
        for (char ch : t) {
            t_set.insert(ch);
            --char_cnt[ch];
        }

        int min_start = -1, min_len;
        int left = 0, len = s.length();
        int remaining_to_see = t_set.size();
        for (int right = 0; right < len; ++right) {
            if (t_set.count(s[right]) != 0 && ++char_cnt[s[right]] == 0) {
                --remaining_to_see;
            }

            while (remaining_to_see == 0) {
                if (min_start == -1 || right - left + 1 < min_len) {
                    min_start = left;
                    min_len = right - left + 1;
                }

                if (t_set.count(s[left]) != 0 && char_cnt[s[left]]-- == 0) {
                    ++remaining_to_see;
                }

                ++left;
            }
        }
        if (min_start == -1) return "";
        else return s.substr(min_start, min_len);
    }
};
