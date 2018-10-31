class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (!n) return {};
        if (n == 1) return {{1}};

        vector<vector<int>> ret(n, vector<int>(n, 0));

        int i = 0, j = -1, val = 0;
        int x = n, y = n-1;
        for (;;) {
            if (!x) break;
            for (int cnt = 0; cnt < x; ++cnt) {
                ++j;
                ret[i][j] = ++val;
            }
            --x;

            if (!y) break;
            for (int cnt = 0; cnt < y; ++cnt) {
                ++i;
                ret[i][j] = ++val;
            }
            --y;

            if (!x) break;
            for (int cnt = 0; cnt < x; ++cnt) {
                --j;
                ret[i][j] = ++val;
            }
            --x;

            if (!y) break;
            for (int cnt = 0; cnt < y; ++cnt) {
                --i;
                ret[i][j] = ++val;
            }
            --y;
        }

        return ret;
    }
};
