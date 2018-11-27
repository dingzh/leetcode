class Solution {
    class DisjointSet {
        vector<int> arr;
    public:
        DisjointSet(int size) {
            arr.reserve(size);
            for (int i = 0; i < size; ++i)
                arr.push_back(i);
        };

        int find(int idx) {
            if (idx != arr[idx]) {
                return arr[idx] = find(arr[idx]);
            } else {
                return idx;
            }
        }

        void join(int idx1, int idx2) {
            int set1 = find(idx1);
            int set2 = find(idx2);
            if (set1 != set2)
                arr[set2] = set1;
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        constexpr int N = 10'005;
        DisjointSet ds( 2 * N );

        for (auto& stone : stones) {
            ds.join(stone[0], stone[1] + N);
        }

        unordered_set<int> seen;
        for (auto& stone : stones) {
            seen.insert(ds.find(stone[0]));
        }

        return stones.size() - seen.size();
    }
};
