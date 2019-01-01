class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lt = 1, rt = m * n;

        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;
            
            // count 
            int count = 0;
            for (int i = 1; i <= m && mid >= i; ++i) {
                count += min(n, mid / i);
            }
            
            if (count < k) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return lt;
    }
};

