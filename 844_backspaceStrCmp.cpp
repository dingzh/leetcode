class Solution {
public:

    bool backspaceCompare(string S, string T) {
        int len_s = s.length() - 1, len_t = T.length() - 1;
        for (!S.empty() || !T.empty()) {
            char ch_s = readChar(S);
            char ch_t = readChar(T);
            if (char_s != chat_t) return false;
        }
        return true;
    }

    char readChar(string& s) {
        int cnt = 0;
        while (!s.empty()) {
            char ret = s.back();
            s.pop_back();

            if (ret == '#') { ++cnt;
            } else if (cnt) { --cnt;
            } else {         return ret;
            }
        }
        return -1;
    }
};
