class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (!row) return ;
        int col = board[0].size();
        if (!col) return ;
        
        queue<pair<int,int>> q;
        for (int c = 0; c < col; ++c) {
            if (board[0][c] == 'O') q.emplace(0, c);
        }
        for (int c = 0; c < col; ++c) {
            if (board[row-1][c] == 'O') q.emplace(row-1, c);
        }
        for (int r = 0; r < row; ++r) {
            if (board[r][0] == 'O') q.emplace(r, 0);
            if (board[r][col-1] == 'O') q.emplace(r, col-1);
        }
        
        
        
        while (!q.empty()) {
            int r, c;
            tie(r, c) = q.front();
            q.pop();
            
            
            if (r >=0 && r < row && c >= 0 && c < col && board[r][c] == 'O') {
                board[r][c] = 'M';
                q.emplace(r-1, c);
                q.emplace(r+1, c);
                q.emplace(r, c-1);
                q.emplace(r, c+1);
            }
        }
        
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                char& ch = board[r][c];
                if (ch == 'O') ch = 'X';
                else if (ch == 'M') ch = 'O';
            }
        }
    }
};
