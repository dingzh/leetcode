class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        if (!row) return ;
        int col = rooms[0].size();
        if (!col) return ;
        
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (rooms[r][c] == 0) {
                    bfs(r, c, rooms);
                }
            }
        }
    }
    
    void bfs(int i, int j, vector<vector<int>>& rooms) {
        constexpr int inf = 2147483647;
        int row = rooms.size(), col = rooms[0].size();   

        queue<int> q;
        q.push(  idx2int(i, j, col) );

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            ++dist;
            while (size--){
                int r, c;
                tie(r, c) = int2idx( q.front(), col );
                q.pop();
                
                // is not gate is not wall and has no shorted path to gate yet
                if (r > 0 && rooms[r-1][c] > dist) { 
                    rooms[r-1][c] = dist;
                    q.push( idx2int(r-1, c, col) );
                }
                if (c > 0 && rooms[r][c-1] > dist) {
                    rooms[r][c-1] = dist;
                    q.push( idx2int(r, c-1, col) );
                }
                if (r + 1 < row && rooms[r+1][c] > dist) {
                    rooms[r+1][c] = dist;
                    q.push( idx2int(r+1, c, col) );
                }
                if (c + 1 < col && rooms[r][c+1] > dist) {
                    rooms[r][c+1] = dist;
                    q.push( idx2int(r, c+1, col));
                }
            }
        }
    }
    
    int idx2int(int r, int c, int col) {
        return r * col + c;
    }
    
    pair<int,int> int2idx(int idx, int col) {
        int r = idx / col;
        int c = idx % col;
        return {r, c};
    }
};
