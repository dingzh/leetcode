class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) {
            return shortestDistanceSame(words, word1);
        } else {
            return shortestDistanceDiff(words, word1, word2);
        }
    }
    
    int shortestDistanceSame(vector<string>& words, string& word) {
        int size = words.size(), idx = -size;
        int ret = size;
        for (int i = 0; i < size; ++i) {
            if (words[i] == word) {
                ret = min(ret, i - idx);
                idx = i;
            }
        }
        return ret;
    }
    
    int shortestDistanceDiff(vector<string>& words, string& word1, string& word2) {
        int idx1 = -1, idx2 = -1, size = words.size();
        int ret = size;
        for (int i = 0; i < size; ++i) {
            if (words[i] == word1) {
                idx1 = i;
                if (idx2 != -1) {
                    ret = min(ret, idx1 - idx2);
                }
            } else if (words[i] == word2) {
                idx2 = i;
                if (idx1 != -1) {
                    ret = min(ret, idx2 - idx1);
                }
            }
        }
        return ret;
    }
};

