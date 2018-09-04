class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0, 1};

        for (int i = 1; i < n; ++i) {
            int inc = 1 << i;
            for (int j = ret.size() - 1; --j; j >= 0) {
                ret.push_back(ret[j] + inc);
            }
        }

        return ret;
    }
};
