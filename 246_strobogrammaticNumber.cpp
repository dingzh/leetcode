class Solution {
    set<pair<char, char>> char_set = {
        {'0','0'}, {'1','1'}, {'6','9'}, {'8','8'},{'9','6'}
    };
public:
    bool isStrobogrammatic(string num) {
        int size = num.size();
        
        for (int i = 0; i <= size / 2; ++i) {
            char lt = num[i], rt = num[size-i-1];
            if (!char_set.count(make_pair(lt, rt))) return false;
        }
        return true;
    }
};
