class Solution {
public:
    string decodeString(string s) {
        stack<int> ctrl_st; // use zero for '['
        stack<string> str_st;
        str_st.push({});
        
        for (auto c : s) {
            if (c == '[') {
                ctrl_st.push(0);
                str_st.push({});
            } else if (c == ']') {
                ctrl_st.pop();
                int k = ctrl_st.top();
                ctrl_st.pop();

                string tmp = move(str_st.top());
                str_st.pop();

                for (int i = 0; i < k; ++i) str_st.top().append(tmp);
            } else if ('0' <= c && c <= '9' ) {
                int k = c - '0'; 
                int top = ctrl_st.top();
                
                if (top) {
                    ctrl_st.top() = top * 10 + k;
                } else {
                    ctrl_st.push(k);
                }
            } else {
                str_st.top().append(1, c); 
            }
        }

        return str_st.top();
    }
};
