class Solution {
public:
    int majorityElement(vector<int>& nums) {
	    int candidate = 0;
	    int counts = 0;
	    for (auto num : nums) {
		if (candidate == num) ++counts;
		else if (counts) --counts;
		else candidate = num;
	    }

	    return candidate;
    }
};
