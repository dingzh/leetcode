class Solution {
    struct Node {
        int ch;
        int valid_from;
        int cnt;
        Node(int ch, int valid_from, int cnt):ch(ch),valid_from(valid_from),cnt(cnt) {}
    };
public:
    string rearrangeString(string s, int k) {
        string ret;

        if (k <= 1) return s;
        array<int, 26> char_cnt;
        char_cnt.fill(0);

        for ( char ch : s ) {
            ++char_cnt[ch-'a'];
        }

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < 26; ++i) if (char_cnt[i]){
            pq.emplace(char_cnt[i], i + 'a');
        }

        queue<Node> q;
        int idx = 0;
        while (true) {
            if (!q.empty()) {
                auto p = q.front();
                if (p.valid_from <= idx) {
                    q.pop();
                    pq.emplace(p.cnt, p.ch);
                }
            }
            
            if (pq.empty()) break;
            int cnt, ch;
            tie(cnt, ch) = pq.top(); pq.pop();
            ret.push_back(ch);
            if (cnt > 1) {
                q.emplace(ch, idx + k, cnt-1);
            }
            ++idx;
        }

        if (!q.empty()) ret.clear();
        return ret;
    }
};
