class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size();

        int prj = N * N;
        for (int i = 0; i < N; ++i) {
            int high = 0;
            for (int j = 0; j < N; ++j) {
                high = max( high, grid[i][j] );
                if (grid[i][j] == 0) --prj;
            }
            prj += high;
        }

        for (int i = 0; i < N; ++i) {
            int high = 0;
            for (int j = 0; j < N; ++j) {
                high = max( high, grid[j][i] );
            }
            prj += high;
        }

        return prj;
    }
};
