class Solution {
public:
    int racecar(int target) {
        if (target == 0) return 0;
        
        set<pair<int, int>> visited; // pos, speed
        visited.emplace(0, 1);
        
        queue<pair<int,int>> q;
        q.emplace(0,1);
        int ret = 0;
        while (!q.empty()) {
            int size = q.size();
            ++ret;
            int pos, speed;
            while (size--) {
                tie(pos, speed) = q.front();
                q.pop();
                
                int n_pos = pos + speed;
                int n_speed = speed > 0 ? -1 : 1;
                if (n_pos == target) return ret;
                
                if (!visited.count(make_pair(n_pos, speed*2))) {
                    q.emplace(n_pos, speed * 2);
                    visited.emplace(n_pos, speed*2);
                }
                    
                if (!visited.count(make_pair(pos, n_speed))) {
                    q.emplace(pos, n_speed);
                    visited.emplace(pos, n_speed);
                }
            }
        }
    }
};
