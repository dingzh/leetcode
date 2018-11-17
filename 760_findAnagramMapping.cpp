class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> val_to_idx;
        int size = B.size();
        if (!size) return {};
        for (int i = 0; i < size; ++i) {
            val_to_idx[B[i]].push_back(i);
        }

        vector<int> ret(size, 0);
        for (int i = 0; i < size; ++i) {
            vector<int>& idx = val_to_idx[A[i]];
            ret[i] = idx.back();
            idx.pop_back();
        }

        return ret;
    }
};
