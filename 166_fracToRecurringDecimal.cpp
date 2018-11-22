class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        string ret;
        
        if (numerator * denominator < 0) {
            ret.push_back('-');
        }
        numerator = max(numerator, -numerator);
        denominator = max(denominator, -denominator);

        ret += to_string(numerator / denominator);
        numerator = numerator % denominator;
        if (numerator == 0) return ret;
        
        ret.push_back('.');
        numerator *= 10;
        
        unordered_map<int, int> numerator_idx;
        while (!numerator_idx.count(numerator)) {
            numerator_idx.emplace(numerator, ret.length());
            ret += to_string(numerator / denominator);
            numerator = numerator % denominator;
            if (numerator == 0) return ret;
            numerator *= 10;
        }
        
        ret.insert(numerator_idx[numerator], 1, '(');
        ret.push_back(')');
        
        return ret;
    }
};
