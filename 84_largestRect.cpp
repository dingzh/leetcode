class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ret = 0, size = heights.size();
        stack<pair<int,int>> stk; //(height, idx)
        stk.emplace(0, -1); 
        
        for (int i = 0; i < size; ++i) {
            int height = heights[i];
            while (stk.top().first > height) {
                auto top = stk.top();
                stk.pop();
                ret = max(ret, top.first * (i - stk.top().second - 1));
            }
            
            stk.emplace(height, i);
        }
        return ret;
    }
};
