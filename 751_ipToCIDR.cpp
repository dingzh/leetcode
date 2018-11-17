class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        long ipInt = ipToInt(ip);
        long ipEnd = ipInt + n;
        long cidr_size = ipInt & (-ipInt);
        vector<string> ret;
        while (cidr_size) {
            if (ipInt + cidr_size <= ipEnd) {
                ret.emplace_back( intToIp(ipInt, cidr_size) );
                ipInt += cidr_size;
                cidr_size = ipInt & (-ipInt);
            } else {
                cidr_size >>= 1;
            }
        }
        
        return ret;
    }
    
    long ipToInt(string ip) {
        long ipInt = 0;
        long tmp;
        stringstream ss(ip);
        for (int i = 0; i < 4; ++i) {
            ss >> tmp;
            ipInt <<= 8;
            ipInt += tmp;
            ss.get();
        }
        return ipInt;
    }
    
    string intToIp(long ipInt, long size) {
        int mask = 0xFF;
        vector<int> tmp;
        string ret;
        for (int i = 0; i < 4; ++i) {
            tmp.push_back(ipInt & mask);
            ipInt >>= 8;
        }
        for (int i = 3; i >= 0; --i) {
            ret += to_string(tmp[i]);
            ret.push_back('.');
        }
        ret.pop_back();
        ret.push_back('/');
        int i = 0;
        while ( (1 << i) < size) ++i;
        ret += to_string(32 - i);
        return ret;
    }
};
