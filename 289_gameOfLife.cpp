class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        if (!m) return;
        int n = board.size();
        if (!n) return;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt;

                if (i > 0 && board[i-1][j] & 1) ++cnt;
                if (j > 0 && board[i][j-1] & 1) ++cnt;
                if (i > 0 && j > 0 && board[i-1][j-1] & 1) ++cnt;

                if (i < m - 1 && board[i+1][j] & 1) ++cnt;
                if (j < n - 1 && board[i][j+1] & 1) ++cnt;
                if (i < m - 1 && j < n -1 && board[i+1][j+1] & 1) ++cnt;

                if (i > 0 && j < n-1 && board[i-1][j+1] & 1) ++cnt;
                if (i < m-1 && j > 0 && board[i+1][j-1] & 1) ++cnt;

                if (cnt == 3) board[i][j] += 2;
                else if (cnt == 2 && res) board[i][j] += 2;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
