class Solution {
    vector<vector<bool>> visited;
public:
    vector<int> 
    hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, 0));
        int prev_cnt = count(grid);
        vector<int> ret;

        for (auto& hit : hits) {
            int& brick = grid[hit[0]][hit[1]];
            if (brick != 0) {
                brick = 0;
                int cnt = count(grid);
                cout << cnt << endl;
                int diff = prev_cnt - cnt;
                ret.push_back( max( 0, diff-1 ) );
                prev_cnt = cnt;
            } else {
                ret.push_back( 0 );
            }
        }
        return ret;
    }

    // count all bricks reachable from the top
    int count(vector<vector<int>>& grid) {
        // rows and cols in range [1, ..]
        int n = grid[0].size();
        int ret = 0;
        
        for (auto& vec : visited) 
            fill(vec.begin(), vec.end(), 0);

        for (int i = 0; i < n; ++i) {
            if (grid[0][i] != 0 && !visited[0][i] )
                ret += dfs(grid, i, visited);
        }

        return ret;
    }

    int dfs(vector<vector<int>>& grid, int idx, 
            vector<vector<bool>>& visited) {
        // first one is zero from the condition of invocation
        int m = grid.size(), n = grid[0].size();
        visited[0][idx] = 1;
        stack<pair<int,int>> stk;
        stk.push( make_pair(0, idx) );

        int ret = 0;
        while (!stk.empty()) {
            ++ret;
            auto& node = stk.top();
            int x = node.first, y = node.second;
            stk.pop();

            if (x > 0 && grid[x-1][y] && !visited[x-1][y] ) {
                stk.push( make_pair(x-1, y) );
                visited[x-1][y] = 1;
            }

            if (x < m-1 && grid[x+1][y] && !visited[x+1][y] ) {
                stk.push( make_pair(x+1, y) );
                visited[x+1][y] = 1;
            }

            if ( y > 0 && grid[x][y-1] && !visited[x][y-1] ) {
                stk.push( make_pair(x, y-1) );
                visited[x][y-1] = 1;
            }

            if ( y < n-1 && grid[x][y+1] && !visited[x][y+1] ) {
                stk.push( make_pair(x, y+1) );
                visited[x][y+1] = 1;
            }
        }
        
        return ret;
    }
};




