class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string result;
        vector<string> ret;
        generateParenthesisAux(n, n, result, ret);
        
        return ret;
    }
    
    void generateParenthesisAux(int open, int close, string& result, vector<string>& ret){
        if (close == 0) {
            ret.push_back(result);
            return ;
        } 
        
        if (open > 0) {
            result.push_back('(');
            generateParenthesisAux(open-1, close, result, ret);
            result.pop_back();
        } 
        if (close > open) {
            result.push_back(')');
            generateParenthesisAux(open, close-1, result, ret);
            result.pop_back();
        }
    }
};
