class Solution {
    const string punct = "!?',;. \n";
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph.push_back(' ');
        unordered_set<string> banned_set;
        unordered_map<string, int> word_cnt;
        for (auto& word : banned) banned_set.insert(word);
        
        string ret;
        int max_cnt = 0;
        
        string word;
        for (auto ch : paragraph) {
            if (punct.find(ch) == string::npos) {
                word.push_back(tolower(ch));
            } else if (!word.empty()){
                if (!banned_set.count(word)) {
                    int cnt = ++word_cnt[word];
                    if (cnt > max_cnt) {
                        ret = word;
                        max_cnt = cnt;
                    }
                }
                word.clear();
            }
        }
        return ret;
    }
};
