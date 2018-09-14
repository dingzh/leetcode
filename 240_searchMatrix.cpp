class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int j = 0, k = n - 1;
        while (j < m && k > -1) {
            if (matrix[j][k] < target) {
                ++j;
            } else if (matrix[j][k] > target) {
                --k;
            } else {
                return true;
            }
        }

        return false;
    }
};
