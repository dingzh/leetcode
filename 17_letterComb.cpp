class Solution {
    array<string, 10> k_mapping = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};

        vector<string> ret;
        string result;

        letterCombAux(0, digits, result, ret);
        return ret;
    }

    void letterCombAux(int idx, string& digits, string& result,
                       vector<string>& ret) {

        if (idx == digits.size()) {
            ret.push_back(result);
            return ;
        }

        int val = digits[idx] - '0';
        for (char ch : k_mapping[val]) {
            result.push_back(ch);
            letterCombAux(idx+1, digits, result, ret);
            result.pop_back();
        }
    }
};
