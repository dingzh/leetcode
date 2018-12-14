class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> res;
        transform(begin(nums), end(nums), back_inserter(res), [](int x) { return (double) x;});

        return solve(res);
    }

    bool solve(vector<double> res) {
        if (res.size() == 1) {
            return fabs( res[0] - 24 ) < 0.0001;
        }
        
        sort(begin(res), end(res));
        do {
            vector<double> tmp = res;
            
            double a = tmp.back(); tmp.pop_back();
            double b = tmp.back(); tmp.pop_back();
            
            if (fabs(b) > 0.0001) {
                tmp.push_back( a/b );
                if (solve(tmp)) return true;
                tmp.pop_back();
            }

            tmp.push_back( a + b );
            if (solve(tmp)) return true;
            tmp.pop_back();

            tmp.push_back( a - b );
            if (solve(tmp)) return true;
            tmp.pop_back();

            tmp.push_back( a * b );
            if (solve(tmp)) return true;
            tmp.pop_back();
        } while ( next_permutation(begin(res), end(res)) );

        return false;
    }
};
