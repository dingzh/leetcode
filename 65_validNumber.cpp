class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        if (len==0) return false;
        
        bool digit_this_part = false;
        bool legal_point = true;
        bool first_part = true;
        
        int begin = 0;
        while (begin < len && s[begin] == ' ') ++begin;
        if (begin < len && s[begin] == '+' || s[begin] == '-') ++begin;

        while (begin < len){
            if (isdigit(s[begin])) {
                digit_this_part = true;
                ++begin;
            } else if (s[begin] == '.' && legal_point && first_part) {
                legal_point = false;
                ++begin;
            } else if (s[begin] == 'e' && first_part && digit_this_part) {
                first_part = false;
                digit_this_part = false;
                ++begin;
                if (s[begin] == '+'|| s[begin] == '-') ++begin;
            } else if (s[begin] == ' ') {
                break;
            } else {
                return false;
            }
        }
        if (!digit_this_part) {
            return false;
        }
        while (begin < len) {
            if (s[begin] != ' ') return false;
            ++begin;
        }
        
        return true;
    }
}; 
