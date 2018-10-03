class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if ( !size ) return {};

        vector<int> ret(size, 0);
        stack<int> stk;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty()) {
                int idx = stk.top();
                if (temperatures[idx] < temperatures[i]) {
                    ret[idx] = i - idx;
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push(i);
        }

        return ret;
    }
};

