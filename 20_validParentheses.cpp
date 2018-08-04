class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
    
        stack<char> st;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }

            if (st.empty()) return false;

            switch(st.top()) {
                case '{':
                    if (c != '}') return false;
                    break;
                case '[':
                    if (c != ']') return false;
                    break;
                case '(':
                    if (c != ')') return false;
                    break;
            }
            st.pop();
        }

        return st.empty();
    }
};
