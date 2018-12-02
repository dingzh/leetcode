/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        
        auto comp = [](const Interval& lhs, const Interval& rhs) {
            return lhs.start > rhs.start || lhs.start == rhs.start && lhs.end > rhs.end;
        };
        priority_queue<Interval, vector<Interval>, decltype(comp)>  pq(comp);
        
        for (auto& hours: schedule) 
            for(auto& interval : hours) 
                pq.emplace(interval);

        vector<Interval> ret;
        if (!pq.size()) return ret;
        
        int free_start = pq.top().start; 
        while (!pq.empty()) {
            auto& top = pq.top();
            if (free_start < top.start) {
                ret.emplace_back(free_start, top.start);
            }
            free_start = max(free_start, top.end);
            pq.pop();
        }
        return ret;
    }
};
