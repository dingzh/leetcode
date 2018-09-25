class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 2) return n;
        
        int* ugly_num = new int[n + 1];
        ugly_num[1] = 1;

        int t2 = 1, t3 = 1, t5 = 1;

        for (int i = 2; i <= n; ++i) {
            int n2 = ugly_num[t2] * 2;
            int n3 = ugly_num[t3] * 3;
            int n5 = ugly_num[t5] * 5;
            int next = min(n2, min(n3, n5));
            
            if (n5 == next) ++t5;
            if (n3 == next) ++t3;
            if (n2 == next) ++t2;

            ugly_num[i] = next;
        }

        return ugly_num[n];
    }
};
