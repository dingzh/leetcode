/**
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    class IntervalComp {
    public:
        bool operator() (const Interval& a, const Interval& b) {
            return a.start > b.start;
        }
    };
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return {};

        vector<Interval> ret;
        priority_queue<Interval, vector<Interval>, IntervalComp>
            pq(intervals.begin(), intervals.end());

        int start = pq.top().start, end = pq.top().end;
        pq.pop();

        while (!pq.empty()) {
            auto& top = pq.top();
            if (top.start <= end) {
                end = max( end, top.end );
            } else {
                ret.emplace_back(start, end);
                start = top.start;
                end = top.end;
            }
            pq.pop();
        }

        ret.emplace_back(start, end);
        return ret;
    }
};
