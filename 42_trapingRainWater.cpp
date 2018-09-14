class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size < 3) return 0;
        
        stack<int> st;
        int ret = 0;
        for (int i = 0; i < size - 1; ++i) {
            int tran = height[i + 1] - height[i];
            if (tran < 0) {
                while (tran++) st.push(i);
            } else if (tran > 0) {
                while (tran-- && !st.empty()) {
                    ret += i - st.top();
                    st.pop();
                }
            }
        }

        return ret;
    }
};
