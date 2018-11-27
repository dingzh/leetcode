class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = people.size();
        if (!size) return {};

        vector<pair<int,int>> ret;
        auto comp = [](const auto& p, const auto& rhs) {
            return p.first < rhs.first || p.first == rhs.first && p.second > rhs.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        for (auto& p : people) pq.push(p);
        
        
        while (!pq.empty()) {
            int h, k;
            tie(h, k) = pq.top();
            pq.pop();
            ret.insert(ret.begin() + k, 1, {h, k});
        }

        return ret;
    }
};
