class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        map<string, function<int(int, int)>> operators = {
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()}
        };

        stack<int> stk;
        for (auto& token : tokens) {
            if (operators.count( token )) {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push( operators[token](x, y) );
            } else {
                stk.push( stoi(token) );
            }
        }
        
        return stk.top();
    }
};
