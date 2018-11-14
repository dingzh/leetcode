class Solution {
    map<char, char> char_set = {
        {'0','0'}, {'1','1'}, {'6','9'}, {'8','8'},{'9','6'}
    };
    string sp = "018";
public:
    vector<string> findStrobogrammatic(int n) {

        vector<string> ret;
        string result(n, '0');
        
        grammaticAux(0, n-1, result, ret);
        return ret;
    }
    
    void grammaticAux(int start, int end, string& result, vector<string>& ret) {
        if (start > end) {
            ret.push_back(result);
            return ;
        }
        
        if (start == end) {
            for (char ch : sp) {
                result[start] = ch;
                ret.push_back(result);
            }
            return ;
        }
        
        for (auto char_pair : char_set) {
            if (start == 0 && char_pair.first == '0') continue;
            result[start] = char_pair.first;
            result[end] = char_pair.second;
            grammaticAux(start+1, end-1, result, ret);
        }
    }
};
