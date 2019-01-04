class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        vector<int> station_dist;
        int size = stations.size();
        if (!size) return 0;
        
        int max_dist = 1;
        for (int i = 1; i < size; ++i) {
            int dist = stations[i] - stations[i-1];
            max_dist = max(max_dist, dist);
            station_dist.push_back(dist);
        }

        double delta = 10e-6;
        
        // double lt = (stations.back() - stations.front()) / double (K + size - 1);
        double lt = 0;
        double rt = max_dist;
        while(rt - lt > delta) {
            
            double mid = (lt + rt) / 2;
            
            int cnt = required(station_dist, mid);
            if (cnt <= K) {
                rt = mid;
            } else {
                lt = mid;
            }
            
        }
        
        return lt;
    }
    
    int required(vector<int>& station_dist, double mid) {
        int ret = 0;
        for (auto dist : station_dist) {
            ret += ceil(dist / mid) - 1;
        }
        
        return ret;
    }
};
