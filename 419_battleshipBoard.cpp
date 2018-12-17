class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        if (!row) return 0;
        int col = board[0].size();
        if (!col) return 0;
        
        int ret = 0;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (board[r][c] == 'X' 
                   && (r == 0 || board[r-1][c] != 'X')
                   && (c == 0 || board[r][c-1] != 'X'))
                    ++ret;
            }
        }
        return ret;
    }
};
