class Solution {
    vector<int> accu_w;
    default_random_engine re{random_device{}()};
    uniform_int_distribution<int> uni;
public:
    Solution(vector<int> w) {
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            accu_w.push_back(sum);
        }
        uni = uniform_int_distribution<int>{0, sum - 1};
    }
    
    int pickIndex() {
        auto p = upper_bound( begin(accu_w), end(accu_w), uni(re) );
        return distance(begin(accu_w), p);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
