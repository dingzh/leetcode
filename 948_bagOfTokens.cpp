class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(begin(tokens), end(tokens));
        
        int size = tokens.size();
        int lt = 0, rt = size - 1;
        
        int max_points = 0;
        while (lt < size && tokens[lt] <= P) {
            P -= tokens[lt++];
            ++max_points;
        }
        
        int points = max_points;
        while (lt <= rt && points > 0) {
            P += tokens[rt--];
            --points;
            
            while (lt <= rt && tokens[lt] <= P) {
                ++points;
                P -= tokens[lt++];
            }
            max_points = max(max_points, points);
        }
        
        return max_points;
    }
};
