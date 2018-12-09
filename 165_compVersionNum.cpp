class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = str2vec(version1);
        auto v2 = str2vec(version2);
        
        int size1 = v1.size(), size2 = v2.size();
        int size = min(size1, size2);
        
        for (int i = 0; i < size; ++i) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }
        
        if (size1 == size2) return 0;
        return size1 > size2 ? 1 : -1;
    }
    
    vector<int> str2vec(string& str) {
        vector<int> ret;
        int num = 0;
        for (char ch : str) {
            if (ch != '.') {
                num = num * 10 + ch - '0';
            } else {
                ret.push_back(num);
                num = 0;
            }
        }
        ret.push_back(num);
        while (!ret.empty() && ret.back() == 0) ret.pop_back();
        return ret;
    }
};
