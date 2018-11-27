class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int> ret(length + 1, 0);
        for (auto& update : updates) {
            int start = update[0], end = update[1] + 1, inc = update[2];
            ret[start] += inc;
            ret[end] -= inc;
        }
        
        int level = 0;
        for (int& val : ret) {
            val += level;
            level = val;
        }
        ret.pop_back();
        return ret;
    }
};
