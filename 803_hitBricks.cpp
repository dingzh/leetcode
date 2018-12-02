class Solution {
    class DisjointSet {
        int size;
        vector<int> parent;
        vector<int> sz;
    public:
        DisjointSet(int k) {
            size = k + 1;
            parent = vector<int>(size, 0);
            sz = vector<int>(size, 1);
            for (int i = 0; i < size; ++i)
                parent[i] = i;
        }

        int find(int key) {
            if (key != parent[key]) parent[key] = find(parent[key]);
            return parent[key];
        }

        void join(int key1, int key2) {
            int p1 = find(key1);
            int p2 = find(key2);
            if (p1 == p2) return ;
            if (sz[p1] < sz[p2]) {
                parent[p1] = p2;
                sz[p2] += sz[p1];
            } else {
                parent[p2] = p1;
                sz[p1] += sz[p2];
            }
        }

        int topSize() {
            return sz[find(size-1)];
        }
    };

    vector<vector<bool>> visited;
public:
    vector<int>
    hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int row = grid.size();
        assert(row);
        int col = grid[0].size();

        // -1 marks will need to add brick back
        for (auto& hit : hits) {
            int r = hit[0], c = hit[1];
            int& val = grid[r][c];
            val = val ? -1 : 0;
        }

        // build initial status of disjoint set
        DisjointSet ds(row * col);
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] != 1) continue;
                int key = r * col + c;
                if (r > 0 && grid[r-1][c] == 1) {
                    ds.join(key, key - col);
                }
                if (c > 0 && grid[r][c-1] == 1) {
                    ds.join(key, key - 1);
                }
            }

        // connect roof to the special point in ds
        const int roof = row * col;
        for (int c = 0; c < col; ++c) {
            if (grid[0][c] == 1)
                ds.join(roof, c);
        }


        // add back brick to check increased brick connected to roof
        int top = ds.topSize();
        vector<int> ret;
        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];
            // no brick here
            if (grid[r][c] != -1) {
                ret.push_back(0);
                continue;
            }
            
            grid[r][c] = 1;
            if (r == 0) ds.join(c, roof);
            // connect in ds
            int key = r * col + c;
            if (r > 0 && grid[r-1][c] == 1) {
                ds.join(key, key - col);
            }
            if (c > 0 && grid[r][c-1] == 1) {
                ds.join(key, key - 1);
            }
            if (r + 1 < row && grid[r+1][c] == 1) {
                ds.join(key, key + col);
            }
            if (c + 1 < col && grid[r][c+1] == 1) {
                ds.join(key, key  + 1);
            }

            int new_top = ds.topSize();
            ret.push_back(max(0, new_top - top - 1));
            top = new_top;
        }

        reverse(begin(ret), end(ret));
        return ret;
    }
};
