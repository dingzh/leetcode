class Solution {
    unordered_map<int, int> start_with, end_with;
    unorderde_set<int> num_seen;
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for (int num : nums) {
            if (num_seen.count(num)) {
                continue;
            }
            num_seen.insert(num);
            
            int start = num, end = num;
            if (start_with.count(num + 1)) {
                end = start_with[num + 1];
                start_with.erase( num + 1 );
                end_with.erase( end );
            }

            if (end_with.count(num - 1)) {
                start = end_with[num - 1];
                end_with.erase( num - 1 );
                start_with.erase( start );
            }

            start_with[start] = end;
            end_with[end] = start;
        }
        
        int max_len = 0;
        for (auto start_end : start_with) {
            max_len = max( max_len, start_end.second - start_end.first );
        }

        return max_len + 1;
    }
};
