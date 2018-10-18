class Solution {
public:
    bool isPalindrome(string s) {
        int lt = 0, rt = s.length() - 1;

        while (lt <= rt) {
            while (lt < rt && !isalnum( s[lt] )) ++lt;
            while (lt < rt && !isalnum( s[rt] )) --rt;
        
            if (tolower( s[lt] ) != tolower( s[rt] )) return false;
            ++lt;
            --rt;
        }
        
        return true;
    }
};
