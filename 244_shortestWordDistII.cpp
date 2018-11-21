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
    
    int shortest(const string& word1, const string& word2) {
        vector<int>& indexes1 = word_indexes[word1];
        vector<int>& indexes2 = word_indexes[word2];
        
        int ret = size;
        int i = 0, j = 0, size1 = indexes1.size(), size2 = indexes2.size();
        
        while (i < size1 && j < size2) {
            int idx1 = indexes1[i], idx2 = indexes2[j];
            if (idx1 < idx2) {
                ret = min(ret, idx2 - idx1);
                ++i;
            } else { // idx1 > idx 2
                ret = min(ret, idx1 - idx2);
                ++j;
            }
        }
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
