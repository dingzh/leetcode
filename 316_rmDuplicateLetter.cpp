class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ret;
        vector<int> cnt(256, 0);

        for (auto ch : s) ++cnt[ch];
        for (auto ch : s) {
            --cnt[ch];
            if (ret.find_first_of(ch) != string::npos) continue;
            while (!ret.empty() && ret.back() >= ch && cnt[ret.back()]) {
                ret.pop_back();
            }
            ret.push_back(ch);
        }
        return ret;
    }
};
