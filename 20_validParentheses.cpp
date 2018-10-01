class Solution {
public:
    bool isValid(string s) {
        map<char, char> mapping;
        mapping.insert({')', '('});
        mapping.insert({']', '['});
        mapping.insert({'}', '{'});
        
        stack<char> stk;
        for (auto ch : s) {
            auto it = mapping.find(ch);
            if (it == mapping.end()) {
                stk.push(ch);
                continue;
            }
            
            if (stk.empty() || it->second != stk.top()) return false;

            stk.pop();
        }

        return stk.empty();
    }
};
