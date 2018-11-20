class NumMatrix {
    vector<vector<int>> matrix_sum;
public:
    NumMatrix(const vector<vector<int>>&& matrix) {
        int row = matrix.size();
        if (!row) return ;
        int col = matrix[0].size();
        if (!col) return ;
        
        matrix_sum = vector<vector<int>>(row, vector<int>(col, 0));
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int lt = c > 0 ? matrix_sum[r][c-1] : 0;
                int up = r > 0 ? matrix_sum[r-1][c] : 0;
                int dg = r > 0 && r > 0 ? matrix_sum[r-1][c-1] : 0;
                matrix_sum[r][c] = matrix[r][c] + lt + up - dg;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = row1 > 0 ? matrix_sum[row1-1][col2] : 0;
        int lt = col1 > 0 ? matrix_sum[row2][col1-1] : 0;
        int dg = row1 > 0 && col1 > 0 ? matrix_sum[row1-1][col1-1] : 0;
        
        return matrix_sum[row2][col2] - up - lt + dg;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
