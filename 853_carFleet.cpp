class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        if (!len) return 0;
        
        vector<pair<int, int>> distance_speed;
        for (int i = 0; i < len; ++i) {
            distance_speed.emplace_back(target - position[i], speed[i]);
        }
        
        sort(begin(distance_speed), end(distance_speed));

        
        long lead_speed, lead_dist;
        tie( lead_dist, lead_speed) = distance_speed[0];
        int fleet_cnt = 1;
        
        for (int i = 1; i < len; ++i) {
            long dist, speed;
            tie(dist, speed) = distance_speed[i];
            
            if (lead_dist * speed < dist * lead_speed) {
                ++fleet_cnt;
                lead_dist = dist;
                lead_speed = speed;
            }
        }
        return fleet_cnt;
    }
};
