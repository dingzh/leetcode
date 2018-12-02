class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> coins;
        coins.push_back(1);
        for (int num : nums) if (num > 0) coins.push_back(num);
        coins.push_back(1);
        
        int size = coins.size();
        vector<vector<int>> memory(size, vector<int>(size, -1));
        
        return maxCoinsAux(coins, 0, size-1, memory);
    }
    
    int maxCoinsAux(vector<int>& coins, int lt, int rt, vector<vector<int>>& memory) {
        if (memory[lt][rt] != -1) return memory[lt][rt];
        
        int ret = 0;
        for (int mid = lt + 1; mid < rt; ++mid) {
            int maxLt = maxCoinsAux(coins, lt, mid, memory);
            int maxRt = maxCoinsAux(coins, mid, rt, memory);
            ret = max(ret, coins[lt] * coins[rt] * coins[mid] + maxLt + maxRt);
        }
        memory[lt][rt] = ret;
        return ret;
    }
};
