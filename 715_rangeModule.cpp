class RangeModule {
    map<int, int> start_to_end;
public:
    RangeModule() {
    }

    // all calls guarantee left < right
    void addRange(int left, int right) {
        auto it = start_to_end.upper_bound(right);
        
        if (it == begin(start_to_end)) {
            start_to_end[left] = right;
            return ;
        }
        
        --it;
        while (it->second >= left) {
            left = min(it->first, left);
            right = max(it->second, right);
            it = start_to_end.erase(it);
            if (it != begin(start_to_end)) it--;
            else break;
        }
        start_to_end[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = start_to_end.upper_bound(left);
        return it != begin(start_to_end) 
            && prev(it)->second >= right && prev(it)->first <= left;
    }

    void removeRange(int left, int right) {
        auto it = start_to_end.lower_bound(right);
        if (it == begin(start_to_end)) {
            // cout << left << ' ' << right << endl;
            return ;
        }
        
        --it;
        if (it->second > right) {
            start_to_end[right] = it->second;
            it->second = right;
        }

        while (it->second > left) {
            if (it->first >= left) {
                it = start_to_end.erase(it);
                if (it != begin(start_to_end)) --it;
                else return ;
            } else {
                it->second = left;
                return ;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
