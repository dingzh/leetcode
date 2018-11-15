// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lt = 1, rt = n;
        while (lt < rt) {
            int mid = lt +  (rt - lt) / 2;
            int res = guess(mid);
            if (res > 0) {
                lt = mid + 1;
            } else if (res < 0) {
                rt = mid - 1;
            } else {
                return mid;
            }
        }
        
        return lt;
    }
};
