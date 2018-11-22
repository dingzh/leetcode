class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row) return true;
        int col = matrix[0].size();
        if (!col) return true;
        
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (r > 0 && c > 0 && matrix[r][c] != matrix[r-1][c-1])
                    return false;
            }
        }
        return true;
    }
};
