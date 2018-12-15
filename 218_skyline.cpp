class Solution {
    struct Event {
        int idx, start, end, height;
        Event(int s, int e, int h) {
            start = s;
            end = e;
            height = h;
            idx = h ? start : end;
        }
        
        bool operator< (const Event& rhs) const {
            return idx > rhs.idx || idx == rhs.idx && height < rhs.height;
        }
    };

public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<Event> events;
        for (vector<int>& building : buildings) {
            events.emplace(building[0], building[1], building[2]);
            events.emplace(building[0], building[1], 0);
        }
        
        vector<pair<int,int>> ret;
        
        int height = 0;
        priority_queue<pair<int,int>> max_height; // height, idx
        while (!events.empty()) {
            auto& event = events.top();
            int idx = event.idx;
            if (event.height) { // new building
                while (!max_height.empty() && max_height.top().second <= idx) max_height.pop();
                max_height.emplace(event.height, event.end);
                int nh = max_height.top().first;
                if (height != nh) {
                    height = nh;
                    ret.emplace_back(idx, nh);
                }
            } else { //some building ended here
                while (!max_height.empty() && max_height.top().second <= idx) max_height.pop();
                int nh = max_height.empty() ? 0 : max_height.top().first;
                if (height != nh) {
                    height = nh;
                    ret.emplace_back(idx, nh);
                }
            }
            events.pop();
        }
        return ret;
    }
};
