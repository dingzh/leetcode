class Solution {
public:
    int maxArea(vector<int>& height) {
        int lt = 0, rt = height.size() - 1;

        int ret = 0;
        while (lt != rt) {
            int area, lowHeight;
            bool moveRight = height[lt] < height[rt];
            lowHeight = moveRight ? height[lt] : height[rt];
            area = lowHeight * (rt - lt);
            if (area > ret) ret = area;

            if (moveRight) {
                while (lt < rt && height[lt] <= lowHeight) ++lt;
            } else {
                while (lt < rt && height[rt] <= lowHeight) --rt;
            }
        }

        return ret;
    }
};
