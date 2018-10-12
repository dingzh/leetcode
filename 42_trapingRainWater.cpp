class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> lheight(size, 0);
        
        int max_height = 0;
        for (int i = 0; i < size; ++i) {
            lheight[i] = max_height;
            max_height = max(max_height, height[i]);
        }

        max_height = 0;
        int ret = 0;
        for (int i = size-1; i > -1; --i) {
            int water = min(lheight[i], max_height) - height[i];
            max_height = max(max_height, height[i]);
            ret += max(0, water);
        }
       
        return ret;
    }
};
