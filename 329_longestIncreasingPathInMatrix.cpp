class Solution {
    unordered_map<int, int> cache;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        if (!col) return 0;
        
        int ret = 0;
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) 
                ret = max(ret, longestIncreasingPathStarting(matrix, i, j));
        return ret;
    }
    
    int longestIncreasingPathStarting(const vector<vector<int>>& matrix, int i, int j) {
        int row = matrix.size();
        int col = matrix[0].size();
        int key = i * col + j;
        
        if (cache.count(key)) return cache[key];
        int ret = 0;
        
        int val = matrix[i][j];
        if (i > 0 && matrix[i-1][j] > val) ret = max(ret, longestIncreasingPathStarting(matrix, i-1, j));
        if (j > 0 && matrix[i][j-1] > val) ret = max(ret, longestIncreasingPathStarting(matrix, i, j-1));
        if (i+1 < row && matrix[i+1][j] > val) ret = max(ret, longestIncreasingPathStarting(matrix, i+1, j));
        if (j+1 < col && matrix[i][j+1] > val) ret = max(ret, longestIncreasingPathStarting(matrix, i, j+1));
        
        ret += 1;
        cache[key] = ret;
        return ret;
    }
};
