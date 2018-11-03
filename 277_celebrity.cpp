// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, cand)) {
                cand = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != cand && (knows(cand, i) || !knows(i, cand))) return -1;
        }
        return cand;
    }
};
