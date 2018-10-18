class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        int ret = 1; // count 2
        int size = ((n - 3) >> 1) + 1;
        deque<bool> isprime(size, true);
        for (int i = 0; i < size; ++i) {
            if (isprime[i]) {
                ++ret;
                int p = (i << 1) + 3;

                for ( long long n = p * p; n < size; n += p ) {
                    isprime[n] = false;
                }
            }
        }

        if ( n & 1 && isprime[size-1]) ret -= 1;

        return ret;
    }
};
