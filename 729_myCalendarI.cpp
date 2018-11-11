class MyCalendar {
    map<int, int> events;
public:
    MyCalendar() = default;

    bool book(int start, int end) {
        auto p = events.upper_bound(start);
        if (p == events.end() || p->second >= end) {
            events[end] = start;
            return true;
        }

        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
