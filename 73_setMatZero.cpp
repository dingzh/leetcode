class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return;
        int n = matrix[0].size();
        if (!n) return;
        
        bool firstRowZero = false;
        for (int k = 0; k < n; ++k) {
            if (!matrix[0][k]) {
                firstRowZero = true;
                break;
            }
        }

        for (int j = 1; j < m; ++j) {
            bool zeroFlag = false;
            vector<int>& row = matrix[j];
            for (int k = 0; k < n; ++k) {
                if (!row[k]) {
                    matrix[0][k] = 0;
                    zeroFlag = true;
                }
            }
            if (zeroFlag) {
                fill(row.begin(), row.end(), 0);
            }
        }

        for (int k = 0; k < n; ++k) {
            if (!matrix[0][k]) {
                for (int j = 1; j < m; ++j) {
                    matrix[j][k] = 0;
                }
            }
        }

        if (firstRowZero) fill(matrix[0].begin(), matrix[0].end(), 0);
    }
};
