class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> dep_cnt(numCourses, 0);
        
        int x, y;
        for (auto& p : prerequisites) {
            tie(x, y) = p;
            ++dep_cnt[x];
            graph[y].push_back(x);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (dep_cnt[i] == 0) q.push(i);
        }
        
        vector<int> ret;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ret.push_back(course);
            
            for (int dep : graph[course]) {
                if (--dep_cnt[dep] == 0) q.push(dep);
            }
        }
        if (ret.size() != numCourses) ret.clear();
        return ret;
    }
};
