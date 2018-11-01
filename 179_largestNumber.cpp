class Solution {
    struct Number {
        string str;
        Number(int x):str(to_string(x)) { }
        bool operator< (const Number& rhs) const {
            return str + rhs.str < rhs.str + str;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<Number> pq;
        for ( int num : nums ) pq.push( num );

        string ret = "";
        while ( !pq.empty() ) { 
            ret += pq.top().str;
            pq.pop();
        }
        return ret;
    }
};
