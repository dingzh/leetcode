class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if ( !size ) return {};

        vector<int> ret(size, 0);
        stack<pair<int,int>> stk;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty()) {
                auto &top = stk.top();
                if (top.first < temperatures[i]) {
                    int idx = top.second;
                    ret[idx] = i - idx;
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push(make_pair(temperatures[i], i));
        }

        return ret;
    }
};

