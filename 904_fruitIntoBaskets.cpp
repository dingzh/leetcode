class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int N = tree.size();
        map<int, int> last_seen;
        
        int max_count = 0, count = 0, start = 0;
        for (int i = 0; i < N; ++i) {
            int fruit = tree[i];
            if (last_seen.size() < 2 || last_seen.count(fruit)) {
                ++count;
                last_seen[fruit] = i;
            } else {
                for (auto& fruit_idx : last_seen) {
                    if (fruit_idx.second != i-1) {
                        start = fruit_idx.second + 1;
                        last_seen.erase(fruit_idx.first);
                    }
                }
                count = i - start + 1;
                last_seen[fruit] = i;
            }

            max_count = max(max_count, count);
        }
        return max_count;
    }
};
