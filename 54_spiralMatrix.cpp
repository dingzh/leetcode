class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();
        if (n == 0) return ret;
        
        int i = 0, j = -1;
        while (true) {
            if (n == 0) break;
            for (int cnt = 0; cnt < n; ++cnt) {
                ++j;
                ret.push_back( matrix[i][j] );
            }
            --n;
            
            --m;
            if (m == 0) break;
            for (int cnt = 0; cnt < m; ++cnt) {
                ++i;
                ret.push_back( matrix[i][j] );
            }
            
            if (n == 0) break;
            for (int cnt = 0; cnt < n; ++cnt) {
                --j;
                ret.push_back( matrix[i][j] );
            }
            --n;
            
            --m;
            if (m == 0) break;
            for (int cnt = 0; cnt < m; ++cnt) {
                --i;
                ret.push_back( matrix[i][j] );
            }
        }
        
        return ret;
    }
};
