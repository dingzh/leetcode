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
    typedef pair<int, bool> Event;
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<Event> events;
        for (Interval& interval : intervals) {
            events.emplace_back(interval.start, false);
            events.emplace_back(interval.end, true);
        }

        sort(events.begin(), events.end(),
                [](Event& x, Event& y){
                    // same time, end first
                    return x.first < y.first || (x.first == y.first && x.second);
                });

        int ret = 0, curr = 0;
        for (auto& event : events) {
            if (event.second) {
                --curr;
            } else {
                ++curr;
                ret = max(ret, curr);
            }
        }
        return ret;
    }
};
