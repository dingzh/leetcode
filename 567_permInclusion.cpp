class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
    
        if (len2 < len1) return false;

        int* cnt = new int[26];
        fill(cnt, cnt+26, 0);

        for (char ch : s1) {
            ++cnt[ch-'a']; 
        }

        for (int i = 0; i < len1; ++i) {
            int pos = s2[i] - 'a';
            --cnt[pos];
        }
        if (isAllZero(cnt, 26)) {
            return true;
        }
        
        int begin = 0, end = len1-1;
        while (end + 1 < len2) {
            int pos = s2[begin] - 'a';
            ++begin;
            ++cnt[pos];

            ++end;
            pos = s2[end] - 'a';
            --cnt[pos];
            
            if (isAllZero(cnt, 26)) return true;
        }

        return false;
    }

    bool isAllZero(int* nums, int size) {
        for (int i = 0; i < size; ++i) {
            if (nums[i]) return false;
        }
        return true;
    }
};
