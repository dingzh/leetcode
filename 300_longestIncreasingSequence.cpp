class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int* least_ending = new int[nums.size()];
        
        least_ending[0] = 1<<31;
        int size = 1;
        
        for (auto num : nums) {
            int pos = findPos(num, least_ending, size);
            if (num > least_ending[pos-1]) {
                least_ending[pos] = num;
                if (pos == size)
                    ++size;
            }
        }

        delete [] least_ending;
        return size-1;       
    }
    
    int findPos(int target, int* nums, int size) {
        int lt = 0, rt = size;
        while (lt < rt) {
            int mid = lt + (rt-lt)/2;
            if (nums[mid] <= target) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return lt;
    }
};






