class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size, 0);
        stack<int> stk;

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            while (!stk.empty()) {
                int stk_num = nums[stk.top()];
                if (stk_num < num) {
                    ret[ stk.top() ] = num;
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push(i);
        }

        for (int num : nums) {
            while (!stk.empty()) {
                int stk_num = nums[stk.top()];
                if (stk_num < num) {
                    ret[ stk.top() ] = num;
                    stk.pop();
                } else {
                    break;
                }
            }
        }

        while (!stk.empty()) {
            ret[ stk.top() ] = -1;
            stk.pop();
        }

        return ret;
    }
};
