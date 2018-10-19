class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        int i = 1;
        while (factorial*i <= k) {
            factorial *= i++;
        }
        --i;

        string ret(n, '0');
        iota(begin(ret), end(ret), '1');
        reverse(ret.begin() + (n-i), ret.end());

        k -= factorial;
        while (k--) {
            nextPerm(ret);
        }

        return ret;
    }

    void nextPerm(string& s) {
        auto invpos = is_sorted_until(s.rbegin(), s.rend());

        if (invpos == s.rend()) {
            reverse(s.begin(), s.end());
            return ;
        }

        auto least_upper_bound = upper_bound(s.rbegin(), invpos, *invpos);
        iter_swap(least_upper_bound, invpos);
        reverse(s.rbegin(), invpos);
    }
};
