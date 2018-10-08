class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        vector<int> ret(len, 0);

        queue<int> char_pos;
        // guaranteed to be in S
        for (int i = 0; i < len; ++i) {
            if (S[i] == C) char_pos.push(i);
        }
        
        char_pos.push( (1<<31) - 1 ); // guard
        int nearest_lt = -1;
        for (int i = 0; i < len; ++i) {
            if (S[i] == C) {
                nearest_lt = i;
                ret[i] = 0;
                continue;
            }

            while (i > char_pos.front()) char_pos.pop();

            if (nearest_lt < 0) {
                ret[i] = char_pos.front() - i;
                continue ;
            }

            int lt_dist = i - nearest_lt;
            int rt_dist = char_pos.front() - i;
            ret[i] = min( lt_dist, rt_dist );
        }

        return ret;
    }
};
