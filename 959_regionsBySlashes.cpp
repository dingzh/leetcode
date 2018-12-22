class Solution {
    class DisjointSet {
        int cluster;
        vector<int> parent;
    public:
        DisjointSet(int size) {
            cluster = 0;
            parent = vector<int>(size, 0);
            for (auto& p : parent) {
                p = cluster++;
            }
        }

        int getCluster() const { return cluster; }

        int find(int idx) {
            if (parent[idx] != idx) parent[idx] = find(parent[idx]);
            return parent[idx];
        }

        void join(int idx1, int idx2) {
            int p1 = find(idx1);
            int p2 = find(idx2);
            if (p1 != p2) {
                --cluster;
                parent[p1] = p2;
            }
        }
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();

        int size = (N * N) << 2;

        DisjointSet ds(size);

        for (int i = 0; i < N; ++i) {
            string& row = grid[i];
            for (int j = 0;  j < N; ++j) {
                int pos = i * N + j;
                int idx = (i * N + j) << 2;
                switch (row[j]) {
                    case '/':
                        ds.join(idx,     idx + 3);
                        ds.join(idx + 1, idx + 2);
                        break;
                    case '\\':
                        ds.join(idx,     idx + 1);
                        ds.join(idx + 2, idx + 3);
                        break;
                    default:
                        ds.join(idx, idx + 1);
                        ds.join(idx, idx + 2);
                        ds.join(idx, idx + 3);
                }
                if (i > 0)     ds.join((pos-N)*4 + 2, idx);
                if (i + 1 < N) ds.join((pos+N)*4,     idx + 2);
                if (j > 0)     ds.join((pos-1)*4 + 1, idx + 3);
                if (j + 1 < N) ds.join((pos+1)*4 + 3, idx + 1);
            }
        }

        return ds.getCluster();
    }
};
