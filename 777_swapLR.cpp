class Solution {
public:
    bool canTransform(string start, string end) {
        int len = start.length();
        if (len != end.length()) return false;

        int wait_for_L = 0, wait_for_R = 0;
        for (int i = 0; i < len; ++i) {
            if (wait_for_L) {
                if (start[i] == 'R' || end[i] == 'R') return false;
                if (start[i] == 'L') --wait_for_L;
                if (end[i] == 'L') ++wait_for_L;
            } else if (wait_for_R) {
                if (start[i] == 'L' || end[i] == 'L') return false;
                if (start[i] =='R') ++wait_for_R;
                if (end[i] == 'R') --wait_for_R;
            } else {
                if (start[i] == end[i]) continue;
                if (start[i] == 'L' || end[i] == 'R') return false;
                if (start[i] == 'R') ++wait_for_R;
                if (  end[i] == 'L') ++wait_for_L;
            }
        }
        return !wait_for_L && !wait_for_R;
    }
};
