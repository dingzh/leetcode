class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
