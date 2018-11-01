class Solution {
public:
    int strStr(string haystack, string needle) {

        //using prime = 2^32, which save us from using modulo
        unsigned int kbase = 257; // which is a prime

        int n_len = needle.length(), h_len = haystack.length();
        if (h_len < n_len) return -1;

        unsigned int n_hash = 0, h_hash = 0;
        for (int i = 0; i < n_len; ++i) {
            // may overflow, but wont be an issue
            n_hash = n_hash * kbase + needle[i];
            h_hash = h_hash * kbase + haystack[i];
        }
        // cout << n_hash << " " << h_hash << endl;

        unsigned int power = 1;
        for (int i = 1; i < n_len; ++i) power *= kbase;

        for (int i = n_len; i < h_len; ++i) {
            if (n_hash == h_hash) {
                // validate
                return i-n_len;
            }

            h_hash -= power * haystack[i-n_len];
            h_hash = h_hash * kbase + haystack[i];
        }

        return h_hash == n_hash ? h_len - n_len : -1;
        // TODO if needed, verify to avoid collision
    }
};
