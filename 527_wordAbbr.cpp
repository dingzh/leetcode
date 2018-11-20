class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<pair<string, int>>> group;
        vector<string> ret(dict.size(), string());

        int idx = 0;
        for (string& word : dict) {
            string abbr = abbrWord(word, 0);
            group[abbr].emplace_back(word, idx);
            ++idx;
        }

        for (auto& g : group) {
            vector<pair<string, int>>& indexed_words = g.second;
            sort(begin(indexed_words), end(indexed_words));
            // for_each(indexed_words.begin(), indexed_words.end(), 
            //          [](auto& p) { cout << p.first << '\t' << p.second << '\t';});
            // cout << endl;
            int size = indexed_words.size();
            vector<int> lcp(size, 0);

            for (int i = 1; i < size; ++i) {
                int p = longestCommPref(indexed_words[i-1].first,
                                        indexed_words[i].first);
                lcp[i] = p;
                lcp[i-1] = max(lcp[i-1], lcp[i]);
            }

            for (int i = 0; i < size; ++i) {
                // cout << lcp[i] << '\t';
                ret[indexed_words[i].second] = abbrWord(indexed_words[i].first, lcp[i]);
                // cout << ret[indexed_words[i].second] << '\t';
            }
            // cout << endl;
        }

        return ret;
    }

    string abbrWord(const string& word, int pref) {
        string ret;
        int len = word.length();
        if (len - pref <= 3) {
            ret = word;
        } else {
            for (int i = 0; i <= pref; ++i) {
                ret.push_back(word[i]);
            }
            ret += to_string( len - pref - 2 );
            ret.push_back(word.back());
        }
        return ret;
    }

    int longestCommPref(const string& a, const string& b) {
        int len = min(a.length(), b.length());

        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) return i;
        }
        return len;
    }
};
