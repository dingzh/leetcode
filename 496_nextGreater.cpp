class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int size = findNums.size();
        unordered_map<int, int> targets;
        vector<int> ret(size, 0);
        for (int i = 0; i < size; ++i) {
            targets[ findNums[i] ] = i;
        }

        
        stack<int> stk;

        for (int num : nums) {
            while (!stk.empty() && stk.top() < num) {
                int top = stk.top();
                stk.pop();
                if (targets.count(top)) {
                    ret[ targets[top] ] = num;
                }
            }
            stk.push(num);
        }

        while(!stk.empty()) {
            int top = stk.top();
            stk.pop();
            if (targets.count(top)) {
                ret[ targets[top] ] = -1;
            }
        }

        return ret;
    }
};
