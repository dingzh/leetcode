class Solution {
    set<int> rotatable = {0, 1, 2, 5, 6, 8, 9};
    set<int> rotate_dif = {2, 5, 6, 9};
public:
    int rotatedDigits(int N) {
        vector<int> vec_N;
        while (N) {
            vec_N.push_back( N % 10);
            N /= 10;
        }
        reverse(begin(vec_N), end(vec_N));
        
        int size = vec_N.size();
        vector<array<int, 4>> memo(size, {-1,-1,-1,-1});
        
        return rotateAux(0, 1, 1, vec_N, memo);
    }
    
    int rotateAux(int idx, int eq, int inv, const vector<int>& vec_N, vector<array<int,4>>& memo) {
        int size = vec_N.size();
        if(idx >= size) return inv ? 0 : 1;
        
        int& m = memo[idx][2*eq + inv];
        if (m >=0) return m;
        
        m = 0;
        for (int digit : rotatable) if (eq == 0 || digit <= vec_N[idx]) {
            int next_eq = (eq == 1 && digit == vec_N[idx]) ? 1 : 0;
            int next_inv = (inv == 1 && rotate_dif.count(digit) == 0) ? 1 : 0;
            m += rotateAux(idx+1, next_eq, next_inv, vec_N, memo);
        }
        return m;
    }
};
