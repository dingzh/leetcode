class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        
        int numerator = 0, denumerator = 1;
        
        while (true) {
            int nnum, nden;
            ss >> nnum;
            if (ss.fail()) break;
            ss.get();
            ss >> nden;
            
            numerator = numerator * nden + denumerator * nnum;
            denumerator = nden * denumerator;
            
            int factor = __gcd(numerator, denumerator);
            numerator /= factor;
            denumerator /= factor;
        }
        
        if (denumerator < 0) {
            numerator *= -1;
            denumerator *= -1;
        }
        
        return to_string(numerator) + "/" + to_string(denumerator);
    }
};
