class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for (auto& word : words) {
            if (matchPattern(word, pattern)) {
                ret.push_back(word);
            }
        }
        return ret;
    }
    
    bool matchPattern(const string& word, const string& pattern) {
        array<char, 256> char_map;
        array<char, 256> char_mapped;
        char_map.fill(0);
        char_mapped.fill(0);
        
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            char a = word[i], b = pattern[i];
            if (char_map[a] == b) continue;
            if (char_map[a] == 0 && char_mapped[b] == 0) {
                char_map[a] = b;
                char_mapped[b] = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
