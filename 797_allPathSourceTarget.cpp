class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;

        vector<vector<int>> ret;
        stack<int> stk;
        stk.push(0);
        vector<int> path;

        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            if (top == -1) {
                path.pop_back();
                continue;
            }

            path.push_back(top);
            if (top == target) {
                ret.emplace_back(path.begin(), path.end());
            }

            stk.push(-1);
            for (int node : graph[top]) {
                stk.push(node);
            }
        }

        return ret;
    }
};
