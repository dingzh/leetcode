class Solution {
    typedef array<int, 2> Pos;
public:
    void solveSudoku(vector<vector<char>>& board) {
        constexpr int N = 9;
        vector<Pos> empty_space;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') 
                    empty_space.push_back( {i, j} );
            }
        }
        
        solve(0, board, empty_space);
    }
    
    bool solve(int pos, vector<vector<char>>& board, vector<Pos>& empty_space) {
        if (pos == empty_space.size()) return true;
        int i = empty_space[pos][0];
        int j = empty_space[pos][1];
        
        
        for ( char digit = '1'; digit <='9'; ++digit ) {
            if (!valid(board, i, j, digit)) continue;
            board[i][j] = digit;
            if ( solve(pos+1, board, empty_space) ) return true;
            board[i][j] = '.';
        }
        board[i][j] = '.';
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j, char digit) {

        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == digit ) return false;
        }

        for (int k = 0; k < 9; ++k) {
            if (board[k][j] == digit ) return false;
        }
        
        int s_i = i - i % 3, s_j = j - j % 3;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) 
                if (board[s_i + i][s_j + j] == digit) return false;
        
        return true;
    }
};
