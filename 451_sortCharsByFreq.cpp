class Solution {
public:
    string frequencySort(string s) {
        map<char, int> char_count;
        for (auto ch : s) {
            ++char_count[ch];
        }

        priority_queue<pair<int, char>> pq;
        for (auto &kv : char_count) {
            pq.push(make_pair(kv.second, kv.first));
        }

        string ret;
        ret.reserve(s.size());
        while (!pq.empty()) {
            auto &top = pq.top();
            char cnt = top.first;
            char ch = top.second;
            for (int i = 0; i < cnt; ++i)
                ret += ch;
            pq.pop();
        }

        return ret;
    }
};
