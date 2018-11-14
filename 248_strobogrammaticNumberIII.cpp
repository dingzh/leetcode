class Solution {
    vector<pair<char, char>> char_pairs = {
        {'0','0'}, {'1','1'},{'6','9'},{'8','8'},{'9','6'}
    };
    unordered_map<int, int> dp;
    vector<char> single = {'0','1','8'};
public:
    int strobogrammaticInRange(string low, string high) {
        
        int l_len = low.length(), h_len = high.length();
        if (l_len > h_len || l_len == h_len && low.compare(high) > 0) return 0;
        dp[1] = 3;
        dp[2] = 5;
        int ret = 0;
        
        for (int i = l_len + 1; i < h_len; ++i){
            ret += count_len(i); // valid without validation
        }
        
        ret += stroboAuxWithBound(l_len, low, high);
        if (l_len != h_len) {
            ret +=  stroboAuxWithBound(h_len, low, high);
        }
        if (low.compare("0") == 0) ++ret;
        return ret;
    }
    
    int stroboAuxWithBound(int len, string& low, string& high) {
        string tmp(len, '0');
        return aux(0, len, low, high, tmp);
    }
    
    int aux(int start, int len, string&low, string&high, string&tmp) {
        
        int ret = 0;
        int lt = start, rt = len - 1 - start;
        if (lt > rt) { // check if in bound
            if ((len > low.length() || low.compare(tmp) <= 0) && 
                (len < high.length()|| high.compare(tmp) >= 0)) {
                return 1;
            }
            else return 0;
        } else if (lt == rt) {
            for (char ch : single) {
                if (lt == 0 && ch == '0') continue;
                tmp[lt] = ch;
                ret += aux(start+1, len, low, high, tmp);
            }
        } else {
            for (auto& char_pair : char_pairs) {
                if (lt == 0 && char_pair.first == '0') continue;
                tmp[lt] = char_pair.first;
                tmp[rt] = char_pair.second;
                ret += aux(lt+1, len, low, high, tmp);
            }
        }
        return ret;
    }

    
    int count_len(int len) {
        if (len == 1) return 3;
        if (len == 2) return 4;
        if (dp.count(len - 2)) {
            int prev = dp[len-2];
            dp[len] = 5 * prev;
            return 4 * prev;
        }
    }
}; 
