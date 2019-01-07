class Solution {
    const vector<vector<int>> next {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}        
    };
    const int div = 1'000'000'007;
public:
    int knightDialer(int N) {
        array<int, 10> prev;
        prev.fill(1);
        
        while (--N) {
            array<int, 10> curr;
            for (int i = 0; i < 10; ++i) {
                int& val = curr[i];
                val = 0;
                for (int n : next[i]) {
                    val += prev[n];
                    val %= div;
                } 
            }
            prev = move(curr);
        }
        
        int ret = 0;
        for (int cnt : prev) {
            ret += cnt;
            ret %= div;
        }
        return ret;
    }
};
