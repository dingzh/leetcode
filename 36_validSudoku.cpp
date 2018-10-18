class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // board size 9x9 is guaranteed
        const int N = 9;
        // chk row
        bool invalid = false;
        for (int i = 0; i < N; ++i) {
            invalid = hasDuplicate(board, i, i+1, 0, N);
            if (invalid) return false;
        }

        for (int j=0; j < N; ++j) {
            invalid = hasDuplicate(board, 0, N, j, j+1);
            if (invalid) return false;
        }

        for (int I = 0; I < N; I += 3) {
            for (int J = 0; J < N; J += 3) {
                invalid = hasDuplicate(board, I, I+3, J, J+3);
                if (invalid) return false;
            }
        }
        return true;
    }
    
    bool hasDuplicate(vector<vector<char>>& board,
            const int rbegin, const int rend,
            const int cbegin, const int cend) {
    
        bool num[9] = {false};
        for (int i = rbegin; i < rend; ++i) {
            for (int j = cbegin; j < cend; ++j) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '1';
                if (num[x]) return true;
                else num[x] = true;
            }
        }

        return false;
    }
};
