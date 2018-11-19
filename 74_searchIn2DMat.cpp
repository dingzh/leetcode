class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (!row) return false;
        int col = matrix[0].size();
        if (!col) return false;
        
        int r = 0, c = col - 1;
        while (r < row && c >= 0) {
            int val = matrix[r][c];
            if (val > target) --c;
            else if (val < target) ++r;
            else return true;
        }
        return false;
    }
};
