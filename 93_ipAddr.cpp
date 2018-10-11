class Solution {
    vector<string> ret;
    vector<int> tmp;
public:
    vector<string> restoreIpAddresses(string s) {
        ipAddrAux(s, 0, 4);
        return ret;
    }
    
    void ipAddrAux(string& s, int begin, int segs) {
        int len = s.length() - begin;
        
        if (segs == 0) {
            if (len == 0) {
                ret.push_back(int2str(tmp));
            } 
            return ;
        } 
        
        for (int i = 1; i < 4 && i <= len; ++i) {
            int num = str2int(s, begin, i);
            if (num > 255) continue;
            tmp.push_back(num);
            ipAddrAux(s, begin + i, segs-1);
            tmp.pop_back();
        }
    }
    
    string int2str(vector<int> nums) {
        string ret = "";
        for (auto num : nums) {
            ret += to_string(num);
            ret += ".";
        }
        ret.pop_back();
        return ret;
    }
    
    int str2int(string&s, int begin, int len) {
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            ret *= 10;
            ret += s[begin+i] - '0';
        }
        if (len > 1 && ret == 0 || ret != 0 && s[begin] == '0') return 256;
        return ret;
    }
};
