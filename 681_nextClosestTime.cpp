class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits(time.begin(), time.end());
        digits.erase(':');
        
        char min_digit = *digits.begin();
        
        auto p = digits.upper_bound(time[4]);
        if (p != digits.end()) {
            time[4] = *p;
            return time;
        } else {
            time[4] = min_digit; // set the the smallest one
        }
        
        p = digits.upper_bound(time[3]);
        if (p != digits.end() && *p < '6') {
            time[3] = *p;
            return time;
        } else {
            time[3] = min_digit;
        }
        
        p = digits.upper_bound(time[1]);
        if (p != digits.end() &&
                (*p < '4' || time[0] == '0' || time[0] == '1') ) {
            time[1] = *p; 
            return time;
        } else {
            time[1] = min_digit;
        }
        
        p = digits.upper_bound(time[0]);
        if (p != digits.end() && *p < '3') {
            time[0] = *p;
        } else {
            time[0] = min_digit;
        }
        
        return time;
    }
};
