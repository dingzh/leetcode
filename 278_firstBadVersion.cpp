// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lt = 1, rt = n;

        while (lt < rt) {
            int mid = (rt - lt) / 2 + lt;
            if (isBadVersion(mid)) {
                rt = mid;
            } else {
                lt = mid + 1;
            }
        }
        return lt;
    }
};
