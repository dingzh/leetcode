class Solution {
    struct Pos {
        int height;
        int start;
        int index;
        Pos(int height, int start, int index):
            height(height), start(start), index(index) {}
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int N = heights.size();
        int maxRect = 0;
        stack<Pos> stk;

        for (int i = 0; i < N; ++i) {
            while (!stk.empty() && stk.top().height > heights[i]) {
                maxRect = max(maxRect, (i - stk.top().start) * stk.top().height);
                stk.pop();
            }
            int start_idx = stk.empty() ? 0 : stk.top().index + 1;
            stk.push({heights[i], start_idx, i});
        }

        return maxRect;
    }
};
