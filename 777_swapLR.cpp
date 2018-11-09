class Solution {
public:
    bool canTransform(string start, string end) {
        int start_len = start.length();
        if (start_len != end.length()) return false;
        
        int lt = 0, rt = start_len - 1;
        
        while (lt <= rt) {
            while (lt <= rt && start[lt] == end[lt]) ++lt;
            if (lt > rt) return true;
            if (start[lt] == 'R' && end[lt] == 'X') {
                for (int i = lt + 1; i <= rt; ++i) {
                    if (start[i] == 'X') {
                        start[i] = 'R';
                        start[lt] = 'X';
                        break;
                    } else if (start[i] == 'L') {
                        return false;
                    }
                }
                
                if (start[lt] != 'X') return false;
            } else if (start[lt] == 'X' && end[lt] == 'L') {
                for (int i = lt + 1; i <= rt; ++i) {
                    if (start[i] == 'L') {
                        start[i] = 'X';
                        start[lt] = 'L';
                        break;
                    } else if (start[i] == 'R') {
                        return false;
                    }
                }
                
                if (start[lt] != 'L') return false;
            } else {
                return false;
            }
            ++lt;
        }
        
        return true;
    }
};
