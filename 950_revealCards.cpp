class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        if (!size) return {};
        
        queue<int> q;
        sort(begin(deck), end(deck), greater<int>());
        
        q.push(deck[0]);
        
        for(int i = 1; i < size; ++i) {
            int x = q.front();
            q.pop();
            q.push(x);
            q.push(deck[i]);
        }
        
        vector<int> ret(size, 0);
        for (int i = size-1; i >= 0; --i) {
            ret[i] = q.front();
            q.pop();
        }
        
        return ret;
    }
};
