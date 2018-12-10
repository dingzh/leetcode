class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        
        if (a.length() > b.length()) swap(a, b);
        int len = a.length();
        
        char c = 0;
        for (int i = 0; i < len; ++i) {
            char cha = a[i] - '0', chb = b[i] - '0';
            char res = cha + chb + c;
            c = res >> 1;
            res = res & 1;
            ret.push_back(res + '0');
        }
        
        for (int i = len; i < b.length(); ++i) {
            char res = b[i] - '0' + c;
            c = res >> 1;
            res = res & 1;
            ret.push_back(res + '0');
        }
        
        if (c) ret.push_back('1');
        
        reverse(begin(ret), end(ret));
        return ret;
    }
};
