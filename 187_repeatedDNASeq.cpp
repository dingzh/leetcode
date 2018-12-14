class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> ret;
        if (len < 10) return ret;

        unordered_map<int, int> seq_to_cnt;
        unordered_map<int, int> dna_to_bits = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        }
        int dna_hash = 0;
        for (int i = 0; i < 10; ++i) {
            dna_hash <<= 2;
            dna_hash += dna_to_bits[s[i]];
        }

        ++seq_to_cnt[dna_hash];
        for (int i = 10; i < len; ++i) {
            dna_hash <<= 2;
            dna_hash += dna_to_bits[s[i]];
            dna_hash &= 0xFFFFF; // only take the last 20 bits
            if (seq_to_cnt[dna_hash]++ == 1) {
                ret.emplace_back(s, i-9, 10);
            }
        }

        return ret;
    }
};
