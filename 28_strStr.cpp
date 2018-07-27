class Solution {
public:
    int strStr(string haystack, string needle) {
	int sLen = haystack.length(), pLen = needle.length();
	if (!pLen) return 0;
	int *next = new int[pLen];
	buildNext(next, pLen, needle);	

	int i = 0, j = 0;
	while (i < sLen && j < pLen) {
		if (j == -1 | haystack[i] == needle[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
	}

	delete[] next;

	return (j == pLen) ? i - j : -1;
    }

    void buildNext(int next[], int len, string pattern) {
    	int j = 0;
	int k = -1;
	next[0] = -1;

	while (j < len - 1) {
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			
			// should not change k in this spacial case, cause k will be of use
			// for handling fail failure in next position where current pos will
			// be a match
			if (pattern[j] == pattern[k]) {
				next[j] = next[k];
			} else {
				next[j] = k;
			}
		} else {
			k = next[k];
		}
	}
    }
};
