class WordDistance {
    int size;
    unordered_map<string, vector<int>> word_indexes;
public:
    WordDistance(vector<string> words) {
        size = words.size();
        for (int i = 0; i < size; ++i) {
            word_indexes[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& indexes1 = word_indexes[word1];
        vector<int>& indexes2 = word_indexes[word2];
        
        int ret = size;
        for (int idx : indexes1) {
            ret = min(ret, distance(idx, indexes2));
            if (ret == 1) return ret;
        }
        
        return ret;
    }
    
    int distance(int idx, vector<int>& indexes) {
        int ret = size;
        auto it = upper_bound(begin(indexes), end(indexes), idx);
        if (it != indexes.end()) ret = min(ret, *it - idx);
        if (it != indexes.begin()) ret = min(ret, idx - *prev(it));
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
