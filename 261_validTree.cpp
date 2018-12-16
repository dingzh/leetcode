class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int size) {
        parent = vector<int>(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
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
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n - 1 != edges.size()) return false;
        
        DisjointSet ds(n);
        
        for (auto& edge : edges) {
            int start, end;
            tie(start, end) = edge;
            if (!ds.join(start, end)) return false;
        }
        return true;
    }
};
