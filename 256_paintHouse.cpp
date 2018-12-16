class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        if (!size) return 0;
        int k = costs[0].size();
        assert(k > 1 || k == 1 && size == 1);
        if (k == 1 && size == 1) return costs[0][0];
        
        vector<int> mincost = costs[0];
        for (int i = 1; i < size; ++i) {
            int cand1, cand2;
            tie(cand1, cand2) = min2_element(mincost);
            auto& cost = costs[i];
            for (int j = 0; j < k; ++j) {
                if (mincost[j] == cand1) 
                    mincost[j] = cand2 + cost[j];
                else 
                    mincost[j] = cand1 + cost[j];
            }
        }
        
        int cand1, cand2;
        tie(cand1, cand2) = min2_element(mincost);
        return cand1;
    }
    
    pair<int, int> min2_element(vector<int> cost) {
        int cand1, cand2;
        auto it = min_element(begin(cost), end(cost));
        cand1 = *it;
        iter_swap(it, begin(cost));
        it = min_element(begin(cost) + 1, end(cost));
        cand2 = *it;
        return {cand1, cand2};
    }
};
