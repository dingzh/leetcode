class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int,int>> range;
        if (!size) return {};
        
        long start = nums[0];
        long expect = start + 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == expect) ++expect;
            else {
                range.emplace_back(start, expect-1);
                start = nums[i];
                expect = start + 1;
            }
        }
        range.emplace_back(start, expect-1);
        
        vector<string> ret;
        transform(range.begin(), range.end(), back_inserter(ret), [](auto& p){
            if(p.first == p.second) {
                return to_string(p.first);
            } else {
                string ret;
                ret += to_string(p.first);
                ret += "->";
                ret += to_string(p.second);
                return ret;
            }
        });
            
        return ret;
    }
};
