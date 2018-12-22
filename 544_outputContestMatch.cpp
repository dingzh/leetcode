class Solution {
public:
    string findContestMatch(int n) {
        vector<string> contests;
        for (int i = 1; i <=n; ++i) {
            contests.push_back(to_string(i));
        }
        
        string tmp;
        for (int len = n; len > 1; len /= 2) {
            for (int i = 0; 2 * i < len; ++i) {

                tmp.push_back('(');
                tmp += contests[i];
                tmp.push_back(',');
                tmp += contests[len - i - 1];
                tmp.push_back(')');
                
                contests[i] = move(tmp);
            }
        }
        return contests[0];
    }
};
