class Solution {
public:
    int calculate(string s) {
        stack<char> optr;
        stack<int>  operands;
        
        optr.push('(');
        s.push_back(')');
        
        bool flag = false;
        int num = 0;
        for (auto ch : s) {
            switch (ch) {
                case ' ': 
                    break;
                    
                case '(':
                    optr.push(ch);
                    break;
                    
                case '+':
                case '-':
                    if (flag) {
                        flag = false;
                        operands.push(num); num = 0;
                    }
                    
                    if (optr.top() != '(') eval(optr, operands);
                    optr.push(ch);
                    break;
                    
                case ')':
                    if (flag) {
                        flag = false;
                        operands.push(num); num = 0;
                    }
                    
                    if (optr.top() != '(') eval(optr, operands);
                    optr.pop();
                    break;
                    
                default:  // integers
                    num = num * 10 + ch - '0';
                    flag = true;
            }
        }
        return operands.top();
    }
    
    void eval(stack<char>& optr, stack<int>& operands) {
        int a = operands.top();  operands.pop();
        int b = operands.top();  operands.pop();
        
        switch(optr.top()) {
            case '+':
                a = b + a;
                break;
            case '-':
                a = b - a;
                break;
        }
        
        optr.pop();
        operands.push(a);
    }
};
