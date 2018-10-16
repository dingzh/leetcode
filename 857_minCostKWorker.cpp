class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int worker_cnt = wage.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < worker_cnt; ++i) {
            workers.emplace_back( wage[i] / (double) quality[i], quality[i] );
        }
        sort( workers.begin(), workers.end() );

        int quality_sum = 0; // the least sum of K-1 workers.
        priority_queue<int> pq;
        for (int i = 0; i < K-1; ++i) {
            int q = workers[i].second;
            pq.push(q);
            quality_sum += q;
        }

        double minwage = numeric_limits<double>::max();
        for (int i = K-1; i < worker_cnt; ++i) {
            quality_sum += workers[i].second;
            minwage = min( minwage, quality_sum * workers[i].first );

            pq.push( workers[i].second );
            quality_sum -= pq.top();
            pq.pop();
        }

        return minwage;
    }
};
