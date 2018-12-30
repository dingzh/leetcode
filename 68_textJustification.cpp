class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        
        int idx = 0, size = words.size();
        while (idx < size) {
            int start = idx;
            int len = 0;
            while (idx < size && len + words[idx].size() + idx - start  <= maxWidth) {
                len += words[idx++].size();
            }
            ret.push_back(getLine(words, start, idx, len, maxWidth));
        }
        
        return ret;
    }
    
    string getLine(vector<string>& words, int start, int end, int len, int maxWidth) {
        string ret;
        ret.reserve(maxWidth);
        
        if (end == words.size()) {
            for (int i = start; i < end; ++i) {
                ret += words[i];
                ret.push_back(' ');
            }
            ret.pop_back();
            while (ret.length() < maxWidth) ret.push_back(' ');
        } else if (end - start == 1) {
            ret += words[start];
            while (ret.length() < maxWidth) ret.push_back(' ');
        } else {
            int space_num = maxWidth - len;
            int space_cnt = end - start - 1;
            int remainder = space_num % space_cnt;
            int quotient  = space_num / space_cnt;
            
            for (int i = 0; i < remainder; ++i) {
                ret += words[start + i];
                ret += string(quotient + 1, ' ');
            }
            
            for (int i = remainder; i < space_cnt; ++i) {
                ret += words[start + i];
                ret +=  string(quotient, ' ');
            }
            
            ret += words[end-1];
        }
        
        return ret;
    }
};
