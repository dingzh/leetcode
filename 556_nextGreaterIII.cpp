class Solution {
public:
    int nextGreaterElement(int n) {
        string n_str = to_string(n);

        auto p = is_sorted_until(n_str.rbegin(), n_str.rend());
        if ( p == n_str.rend() ) return -1;

        auto q = upper_bound(n_str.rbegin(), p, *p);
        iter_swap(p, q);
        reverse(n_str.rbegin(), p);

        long long ret = stoll(n_str);

        return ret > numeric_limits<int>::max() ? -1 : (int) ret;
    }
};
