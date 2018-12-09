class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<queue<pair<int, int>>> wq(256, queue<pair<int,int>>());
        
        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            // todo check if word empty
            char ch = word[0];
            wq[ch].emplace(i, 0);
        }
        
        for (char ch : S) {
            queue<pair<int,int>>& q = wq[ch];
            int size = q.size();
            while (size--) {
                int widx, chidx;
                tie(widx, chidx) = q.front();
                q.pop();
                ++chidx;
                string& word = words[widx];
                if (chidx == word.length()) ++ret;
                else { wq[word[chidx]].emplace(widx, chidx); }
            }
        }
        return ret;
    }
};
