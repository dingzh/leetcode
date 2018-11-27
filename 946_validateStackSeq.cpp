class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        if (pushed.size() != popped.size()) return false;
        
        int size = pushed.size();
        int idx_pushed = 0, idx_popped = 0;
        while (idx_popped < size) {
            int element = popped[idx_popped++];

            if (!stk.empty() && element == stk.top()) {
                stk.pop();
                continue;
            } 
                
            while (idx_pushed < size && pushed[idx_pushed] != element ) 
            stk.push(pushed[idx_pushed++]);

            if (idx_pushed == size) return false;
            else ++idx_pushed;
        }
        
        return true;
    }
};
