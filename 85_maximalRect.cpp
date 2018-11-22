class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        if (!col) return 0;
        
        int ret = 0;        
        vector<int> dp(col, 0);
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                dp[c] = matrix[r][c] == '1' ? dp[c] + 1 : 0;
            }
            ret = max(ret, maxRectHist(dp));
        }

        return ret;
    }
    
    int maxRectHist(vector<int>& hist) {
        hist.push_back(0);
        int size = hist.size();
        int ret = 0;
        stack<pair<int,int>> stk; // <height, idx>
        stk.emplace(-1,-1); // guard
        
        for (int i = 0; i < size; ++i) {
            while (stk.top().first > hist[i]) { // will never be empty
                int height = stk.top().first;
                stk.pop();
                ret = max(ret, height * (i - stk.top().second - 1));
            }
            
            stk.emplace(hist[i],i);
        }
        return ret;
    }
};
