class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        vector<int> leftDist(size, 0);

        int prev = -size;
        for (int i = 0; i < size; ++i) {
            if (seats[i]) {
                leftDist[i] = 0;
                prev = i;
            } else {
                leftDist[i] = i - prev;
            }
        }

        int max_dist = 0;
        prev = size * 2;
        for (int i = size - 1; i > -1; --i) {
            if (seats[i]) {
                prev = i;
            } else {
                int dist = min(leftDist[i], prev - i);
                max_dist = max( dist, max_dist );                
            }

        }
        return max_dist;
    }
};
