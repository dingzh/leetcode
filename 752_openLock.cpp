class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start("0000");
        if (start == target) return 0;

        unordered_set<string> set_deadends;
        for(auto &str : deadends) set_deadends.emplace(str);
        if (set_deadends.count(start)) return -1;

        queue<string> q;
        q.push(start);
        set_deadends.emplace(start);

        int step_cnt = 0;
        int curr_step_remain = 1;
        while (curr_step_remain) {
            auto& front = q.front();
            if (target == front) return step_cnt;
            
            curr_step_remain -= 1;
            push_next_states(front, q, set_deadends);
            q.pop();
            
            if (!curr_step_remain) {
                ++step_cnt;
                curr_step_remain = q.size();
            }
        }

        return -1;
    }

    void push_next_states
    (const string& str, queue<string>& q, unordered_set<string>& set_deadends) {
        for (int i = 0; i < str.length(); ++i) {
            string next_state(str);
            char ch = str[i];
            if (ch == '9')   next_state[i] = '0';
            else next_state[i] = ch + 1;

            if (!set_deadends.count(next_state)) {
                set_deadends.emplace(next_state);
                q.emplace(next_state);
            }

            if (ch == '0')   next_state[i] = '9';
            else next_state[i] = ch - 1;

            if (!set_deadends.count(next_state)) {
                set_deadends.emplace(next_state);
                q.emplace(next_state);
            }
        }
    } 
};
