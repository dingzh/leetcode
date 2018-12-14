class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
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
