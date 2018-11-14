class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) return size;
        
        vector<int> candies(size, 1);
        
        // first pass, left to right
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        int ret = candies[size-1];
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
            ret += candies[i];
        }
        return ret;
    }
};
