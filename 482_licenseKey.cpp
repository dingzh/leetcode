class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        queue<char> q;

        for (auto ch : S) {
            if (ch == '-') continue;
            q.push(toupper(ch));
        }

        int size = q.size();
        string ret;
        for (int i = 0; i < size%K; ++i) {
            ret += q.front();
            q.pop();
        }
        if (size%K) ret += "-";

        while (!q.empty()) {
            for (int i = 0; i < K; ++i) {
                ret += q.front();
                q.pop();
            }
            ret += "-";
        }
        ret.pop_back();
        return ret;
    }
};
