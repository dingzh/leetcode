class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> ret;

        int plen = p.size(), slen = s.size();
		if (plen > slen) return ret;

        int pending = 0;
        array<int, 256> char_cnt;
        char_cnt.fill(0);
        for (auto ch : p) if (char_cnt[ch]++ == 0) ++pending;
        
		for (int i = 0; i < plen; ++i) {
			if (--char_cnt[s[i]] == 0) --pending;
		}
        if (pending == 0) ret.push_back(0);
        
        for (int i = plen; i < slen; ++i) {
            if (char_cnt[s[i-plen]]++ == 0) ++pending;
			if (--char_cnt[s[i]] == 0) --pending;
			if (pending == 0) ret.push_back(i - plen + 1);
        }
		
		return ret;
    }
};

