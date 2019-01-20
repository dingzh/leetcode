class Solution {
public:
    string solveEquation(string equation) {
        int eq_pos = equation.find('=');
        
        auto lhs = equation.substr(0, eq_pos);
        auto rhs = equation.substr(eq_pos+1);
        
        auto plhs = parse(lhs);
        auto prhs = parse(rhs);
        
        int coeff = plhs.first - prhs.first;
        int cons  = prhs.second - plhs.second;

        if (coeff == 0 && cons == 0) return "Infinite solutions";
        if (coeff == 0 && cons != 0) return "No solution";
        string ret = "x=";
        ret += to_string(cons / coeff);
        
        return ret;
    }
    
    pair<int,int> parse(const string& str) {
        int coeff = 0;
        int cons = 0;
        stringstream ss(str);
        
        int ch;
        while ( (ch = ss.peek()) != EOF ) {
            int sign = 1, val = 1;
            if (ch == '+' || ch == '-') {
                ss.get();
                if (ch == '-') sign = -1;
            }
            
            ch = ss.peek();
            if (isdigit(ch)) ss >> val;
            
            ch = ss.peek();
            if (!ss.fail() && ch == 'x') {
                coeff += sign * val;
                ss.get();
            } else {
                cons += sign * val;
            }
        }
        return make_pair(coeff, cons);
    }
};
