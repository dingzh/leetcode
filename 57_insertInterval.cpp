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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        if (!size) return { newInterval };

        vector<Interval> ret;

        int i = 0;
        while (i < size && intervals[i].end < newInterval.start) {
            ret.emplace_back(intervals[i++]);
        }

        while (i < size && intervals[i].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            ++i;
        }
        ret.emplace_back(newInterval);

        while (i < size) {
            ret.emplace_back(intervals[i++]);
        }
        return ret;
    }
};
