class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string tmp = "";
        for (int i = 1; i < n; ++i) {
            int count = 0;
            char val = '\0';
            for (char ch : prev) {
                if (ch != val) {
                    if (count != 0) {
                        tmp += to_string(count);
                        tmp.push_back(val);
                    } 
                    count = 1;
                    val = ch;
                } else {
                    ++count;
                }
            }
            if (count != 0) {
                tmp += to_string(count);
                tmp.push_back(val);
            }
            prev = move(tmp);
        }
        return prev;
    }
};
