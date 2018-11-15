class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] != 0 && checkStart(i, nums)) return true;
        }
        return false;
    }
    
    bool checkStart(int idx, vector<int>& nums) {
        const bool forward = nums[idx] > 0;
        unordered_set<int> visited;
        
        while (!visited.count(idx)) {
            int val = nums[idx];
            visited.insert(idx);
            if (nums[idx] == 0 || forward && val < 0 || !forward && val > 0) 
                return false;
            
            nums[idx] = 0; // not going into this path later
            
            idx = (idx + val) % nums.size();
        }
        
        return visited.size() > 1;
    }
};
