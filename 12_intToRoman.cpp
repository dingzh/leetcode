class Solution {
    const int N = 13;
    const int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string token[] = 
        {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX", "V", "IV","I"};
public:
    string intToRoman(int num) {
        string ret;
        for (int i = 0; i < N && num; ++i) {
            int rep = num / val[i];
            num %= val[i];
            for (int j = 0; j < rep; ++j) {
                ret += token[i];
            } 
        }
        return ret;
    }
};
