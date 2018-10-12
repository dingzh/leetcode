class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int ret = 0, lt = 0, rt = size -1;
        int lmax = 0, rmax = 0;

        while (lt <= rt) {
            if (lmax <= rmax) {
                ret += max(0, lmax - height[lt]);
                lmax = max(height[lt], lmax);
                ++lt;
            } else {
                ret += max(0, rmax - height[rt]);
                rmax = max(height[rt], rmax);
                --rt;
            }
        }
        return ret;
    }
};
