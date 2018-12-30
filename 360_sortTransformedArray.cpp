class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        auto func = [&a, &b, &c](int x) { return a * x * x + b * x + c; };
        
        if (a == 0) {
            vector<int> ret;
            transform(begin(nums), end(nums), back_inserter(ret), func);
            if (b < 0) reverse(begin(ret), end(ret));
            return ret;
        }
        
        double mid = - b / (2.0 * a);
        vector<int> ret1, ret2;
        for (int num : nums) {
            int res = func(num);
            if (num <= mid) ret1.push_back(res);
            else ret2.push_back(res);
        }
        if (a < 0) reverse(begin(ret2), end(ret2));
        else reverse(begin(ret1), end(ret1));
        
        return merge(ret1, ret2);
    }
    
    vector<int> merge(vector<int>& vec1, vector<int>& vec2) {
        int p1 = 0, size1 = vec1.size();
        int p2 = 0, size2 = vec2.size();
        
        vector<int> ret;
        while (p1 < size1 && p2 < size2) {
            if (vec1[p1] < vec2[p2]) {
                ret.push_back(vec1[p1++]);
            } else {
                ret.push_back(vec2[p2++]);
            }
        }
        
        while (p1 < size1) ret.push_back(vec1[p1++]);
        while (p2 < size2) ret.push_back(vec2[p2++]);
        return ret;
    }
};
