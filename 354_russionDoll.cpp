class Solution {
    class envelopeLess {
    public:
        bool operator() (const pair<int, int>& a, const pair<int,int>& b) {
            return a.first < b.first || a.first == b.first && a.second > b.second;
        }
    };
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), envelopeLess());
        vector<int> height;
        for (auto& env : envelopes) {
            height.push_back(env.second);
        }
        return longestIncSubseq(height);
    }

    int longestIncSubseq(vector<int> nums) {
        vector<int> least_ending = vector<int>(nums.size()+1, 0);
        
        int size = 1;
        least_ending[0] = 1<<31;

        for (auto num : nums) {
            int pos = findPos(num, least_ending, size);
            if (num > least_ending[pos-1]) {
                least_ending[pos] = num;
                if (pos == size) ++size;
            }
        }
        return size-1;
    }

    int findPos(int target, vector<int>& nums, int size) {
        int lt = 0, rt = size;
        while (lt < rt) {
            int mid = lt + (rt-lt)/2;
            if (nums[mid] <= target) { lt = mid + 1;
            } else { rt = mid; }
        }
        return lt;
    }
};


