class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int size = flowers.size();
        if (size - 2 < k) return -1;

        vector<int> indexed_tree(size+1, 0);
        vector<int> status(size+1, 0);

        for (int i = 0; i < size; ++i) {
            int pos = flowers[i];
            status[pos] = 1;
            update(pos, 1, indexed_tree);
            
            int prev_pos = pos - k - 1, next_pos = pos + k + 1;
            int bloom_till_pos = getsum(pos, indexed_tree);
            if (prev_pos > 0 && status[prev_pos]
                    && bloom_till_pos == 1 + getsum(prev_pos, indexed_tree)) {
                return i+1;
            }
            if (next_pos <= size && status[next_pos]
                    && bloom_till_pos + 1 == getsum(next_pos, indexed_tree)){
                return i+1;
            }
        }
        return -1;
    }

    void update(int pos, int delta, vector<int>& indexed_tree) {
        int size = indexed_tree.size();
        while (pos < size) {
            indexed_tree[pos] += delta;
            pos += pos & -pos;
        }
    }

    int getsum(int pos, vector<int>& indexed_tree) {
        int ret = 0;
        while (pos > 0) {
            ret += indexed_tree[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
};
