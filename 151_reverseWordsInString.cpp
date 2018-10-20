class Solution {
public:
    void reverseWords(string &s) {
        int len = rmExtraSpace(s);
        s.erase(s.begin() + len, s.end());
        reverse(s.begin(), s.end());

        size_t start = 0, end;
        while ( (end = s.find(' ', start)) != string::npos ) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }

        reverse(s.begin() + start, s.end());
    }

    int rmExtraSpace(string &s) {
        int i = 0, write_idx = 0, len = s.length();
        while (i < len && s[i] == ' ') ++i;
        
        int cnt = 0;
        while (i < len) {
            if (s[i] != ' ') {
                s[write_idx++] = s[i];
                cnt = 0;
            } else if(!cnt) {
                cnt = 1;
                s[write_idx++] = s[i];
            }
            ++i;
        }
        
        if (write_idx > 0 && s.back() == ' ') {
            --write_idx;
            s.pop_back();
        }
        return write_idx;
    }
};
