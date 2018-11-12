class MyCalendarTwo {
    map<int, int> boundary_count;
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        int active_event = 0;
        boundary_count[start]++;
        boundary_count[end]--;

        for (auto& bound_count : boundary_count) {
            active_event += bound_count.second;
            if (active_event > 2) {
                boundary_count[start]--;
                boundary_count[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
