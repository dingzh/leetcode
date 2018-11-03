class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = tree.size();
        map<int, int> fruit_last_seen;

        int ret = 0;
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (fruit_last_seen.size() < 2 || fruit_last_seen.count(tree[i])) {
                ++count;
            } else {
                auto first = fruit_last_seen.cbegin();
                auto second = next(first);
                int start = 0;
                if (first->second < second->second) {
                    start = first->second;
                    fruit_last_seen.erase(first);
                } else {
                    start = second->second;
                    fruit_last_seen.erase(second);
                }
                ret = max(ret, count);
                count = i - start;
            }
            fruit_last_seen[tree[i]] = i;
        }
        ret = max(ret, count);
        return ret;
    }
};
