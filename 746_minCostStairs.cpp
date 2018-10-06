class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int f0 = 0, f1 = 0;

        for (int i = 0; i < cost.size(); ++i) {
            int tmp = cost[i] + min(f0, f1);
            f0 = f1;
            f1 = tmp;
        }

        return min(f0, f1);
    }
};
