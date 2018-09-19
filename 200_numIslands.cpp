class DisjointSet {
    int* data;
    int size;
public:
    DisjointSet(int x): size(x) {
        data = new int[size + 1];
        for (int i = 0; i < size; ++ i) data[i] = i;
    }

    int find(int idx) {
        if (idx == data[idx]) return idx;
        return data[idx] = find(data[data[idx]]);
    }

    bool isroot(int idx) {
        return data[idx] == idx;
    }

    void unify(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y) return;
        data[root_x] = root_y;
    }

    ~DisjointSet() { delete data; }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;

        DisjointSet ds( m*n );

        // special case: first row
        for (int j = 1; j < n; ++j) {
            if (grid[0][j] == '1' && grid[0][j-1] == '1') ds.unify(j, j-1);
        }

        for (int i = 1; i < m; ++i) {
            // special case: first column
            if (grid[i][0] == '1' && grid[i-1][0] == '1') ds.unify( i*n, (i-1)*n );
            
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == '1') {
                    if (grid[i-1][j] == '1')  ds.unify( i*n + j, (i-1)*n + j );
                    if (grid[i][j-1] == '1')  ds.unify( i*n + j, i*n + j-1);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]  == '1' && ds.isroot(i*n + j)) ++ret;
            }           
        }

       return ret;
    }
};


