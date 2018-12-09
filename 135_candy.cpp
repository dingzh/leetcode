class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size <= 1) return size;
        ratings.push_back(ratings.back()); // dummy 
        
        int ret = 0;
        int prev = 0;
        int inc = 0, dec = 0;
        for (int i = 0; i < size ; ++i) {
            const int curr = 
                ratings[i] < ratings[i+1] ? 1 : (ratings[i] > ratings[i+1] ? -1 : 0);
            
            if (prev == 0) {
                inc = 0;
                dec = 0;
                if (curr == 0) ++ret;
                else if (curr == -1) ++dec;
                else ++inc;
            } else if (prev == 1) {
                ++inc;
                if (curr == 0) ret += count(inc);
                else if (curr == -1) ++dec;
            } else {
                ++dec;
                if (curr == 0) ret += count(dec) + count(inc) - min(dec, inc);
                else if (curr == 1) {
                    // minus one cause later caculation will count this one
                    ret += count(dec) + count(inc) - min(dec, inc) - 1 ;
                    inc = 1;
                    dec = 0;
                }
            }
            prev = curr;
        }
        return ret;
    }
    
    int count(int n) {
        return (n + 1) * n / 2;
    }
};
