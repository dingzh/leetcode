class Solution {
    class DisjointSet {
        vector<int> parent;
    public:
        DisjointSet(int size) {
            parent = vector<int>(size, 0);
            for (int i = 0; i < size; ++i)
                parent[i] = i;
        }
        // return false if already joined
        bool join(int idx1, int idx2) {
            int p1 = find(idx1);
            int p2 = find(idx2);
            if (p1 == p2) return false;
            parent[p1] = p2;
            return true;
        }

        int find(int idx) {
            if (parent[idx] != idx) parent[idx] = find(parent[idx]);
            return parent[idx];
        }
    };
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> parent(size + 1, 0);

        vector<pair<int,int>> candidates;

        for (auto& edge : edges) {
            int start = edge[0], end = edge[1];
            if (parent[end]) {
                candidates.emplace_back(start, end);
                candidates.emplace_back(parent[end], end);
            } else {
                parent[end] = start;
            }
        }

        DisjointSet ds(size + 1);
        for (auto& edge : edges) {
            int start = edge[0], end = edge[1];
            if (!candidates.empty() && make_pair(start, end) == candidates[0])
                continue; // ignore first
            if (!ds.join(start, end)) {
                // loop detected
                if (!candidates.empty()) return {candidates[1].first, candidates[1].second};
                else return {start, end};
            }
        }

        return {candidates[0].first, candidates[0].second};
    }
};
