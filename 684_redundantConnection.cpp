class Solution {
    class DisjointSet {
        vector<int> parent;
    public:
        DisjointSet(int size):parent(size + 1, 0) {
            for (int i = 0; i <= size; ++i) {
                parent[i] = i;
            }
        }
        
        int find(int idx) {
            int &ret = parent[idx];
            if (ret != idx) ret = find(ret);
            return ret;
        }
        
        // return false if alroady in same set
        bool join(int idx1, int idx2) {
            int set1 = find(idx1);
            int set2 = find(idx2);
            parent[set1] = set2;
            return set1 != set2;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        
        DisjointSet ds(size);
        
        for (auto& edge : edges) {
            if (!ds.join(edge[0], edge[1]))
                return edge;
        }
        // not gonna happen
        return {};
    }
};
