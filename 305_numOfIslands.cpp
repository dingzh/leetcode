class Solution {
    class DisjointSet {
        vector<int> parent;
    public:
        DisjointSet(int size) {
            parent = vector<int>(size, 0);
            for (int i = 0; i < size; ++i) parent[i] = i;
        }
        
        int find(int idx) {
            if (parent[idx] != idx) parent[idx] = find(parent[idx]);
            return parent[idx];
        }
        
        bool join(int idx1, int idx2) {
            int p1 = find(idx1);
            int p2 = find(idx2);
            if (p1 == p2) return false;
            parent[p1] = p2;
            return true;
        }
    };
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> sea(m, vector<int>(n, 0));
        vector<int> ret;
        int cnt = 0;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0},{-1,0}};
        DisjointSet ds(m * n);
        
        for (auto& pos : positions) {
            int r, c;
            tie(r, c) = pos;
            sea[r][c] = 1;
            ++cnt;
            int key = r * n + c;
            
            for (auto& dir : dirs) {
                int i, j;
                tie(i, j) = dir;
                int nr = r + i, nc = c + j;
                if (nr >= 0 && nr < m && nc >=0 && nc < n && sea[nr][nc]) {
                    int nkey = nr * n + nc;
                    if (ds.join(key, nkey)) --cnt;
                }
            }
                
            ret.push_back(cnt);
        }
        
        return ret;
    }
};
