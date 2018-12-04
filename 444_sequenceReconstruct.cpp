class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int N = org.size();
        
        vector<set<int>> graph(N + 1, set<int>());
        vector<int> parent_cnt(N + 1, 0);
        vector<int> seen(N + 1, 0);
        
        // build graph
        for (auto& seq : seqs) if ( !seq.empty() ) {
            int start = seq[0];
            if (start < 1 || start > N) return false;
            ++seen[start];
            
            for (int i = 1; i < seq.size(); ++i) {
                int end = seq[i];
                if (end < 1 || end> N) return false;
                ++seen[end];
                if (!graph[start].count(end)) {
                    graph[start].insert(end);
                    ++parent_cnt[end];
                    start = end;
                }
            }
        }
        
        // if any element not seen return false
        for (int i = 1; i <= N; ++i) {
            if (!seen[i]) return false;
        }
        
        // topological sort
        queue<int> nextq;
        for (int i = 1; i < parent_cnt.size(); ++i) {
            if (!parent_cnt[i]) nextq.push(i);
        }
        
        int idx = 0;
        if (nextq.size() != 1) return false; 
        while(nextq.size() == 1) {
            int node = nextq.front();
            nextq.pop();
            // idx < N is guaranteed, each time only one element is added iterated
            if (node != org[idx++]) return false;
            
            for (auto end : graph[node]) {
                if (--parent_cnt[end] == 0) nextq.push(end);
            }
        }
        
        return nextq.empty() && idx == N;
    }
};
