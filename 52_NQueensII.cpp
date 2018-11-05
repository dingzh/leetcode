class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> occupied;
        solveNQueensAux(n, occupied, ret);
        
        return ret;
    }
    
    void solveNQueensAux(int n, vector<int>& occupied, int& ret) {
        if (occupied.size() == n) {
            ++ret; return ;
        }

        for (int pos = 0; pos < n; ++pos) {
            bool legal = checkStatus(occupied, pos);
            if (legal) {
                occupied.push_back(pos);
                solveNQueensAux(n, occupied, ret);
                occupied.pop_back();
            }
        }
    }

    bool checkStatus(vector<int>& occupied, int pos) {
        int idx = occupied.size(); // index of this new element
        int left_diag = idx + pos;
        int right_diag = pos - idx;
        for (int i = 0; i < idx; ++i) {
            if (pos == occupied[i]) return false;
            if (left_diag == i + occupied[i]) return false;
            if (right_diag == occupied[i] - i) return false;
        }
        return true;
    }
};
