class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        if (row <= 2) return 0;
        int col = heightMap[0].size();
        if (col <= 2) return 0;
        
        vector<vector<int>> visited(row, vector<int>(col, 0));
        // pair <height, position>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for (int r = 0; r < row; ++r ) {
            visited[r][0] = 1;
            visited[r][col-1] = 1;
            pq.emplace(heightMap[r][0], r * col);
            pq.emplace(heightMap[r][col-1], r * col + col - 1);
        }
        
        for (int c = 1; c + 1 < col; ++c) {
            visited[0][c] = 1;
            visited[row-1][c] = 1;
            pq.emplace(heightMap[0][c], c);
            pq.emplace(heightMap[row-1][c], (row-1)*col + c);
        }
        
        vector<pair<int, int>> dirs = {{0,1}, {0,-1},{1,0},{-1,0}};
        int cnt = (row - 2) * (col - 2);
        int ret = 0;
        while (cnt > 0) {
            auto top = pq.top();
            pq.pop();
            int height = top.first;
            int r = top.second / col;
            int c = top.second % col;
            for (auto dir : dirs) {
                int nr = r + dir.first, nc = c + dir.second;
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    --cnt;
                    ret += max(0, height - heightMap[nr][nc]);
                    pq.emplace(max(height, heightMap[nr][nc]), nr * col + nc);
                }
            }
        }
        
        return ret;
    }
};
