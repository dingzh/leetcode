class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unodrder_map<int, int> num_cnts;
        for (auto num : nums) {
            ++num_cnt[num];
        }

        priority_queue<pq_node> pq;
        for (auto& kv : nums_cnts) {
            pq.emplace(make_pair(kv.second, kv.first));
        }

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            int num = pq.top()->second;
            pq.pop();
            ret.push_back(num);
        }

        return ret;
    }
};
