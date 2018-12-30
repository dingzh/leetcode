class Solution {
public:
    string crackSafe(int n, int k) {
        if (n == 1) {
            string ret;
            for (int i = 0; i < k; ++i) {
                ret.push_back('0' + i);
            }
            return ret;
        }
        
        if (k == 1) 
            return string(n, '0');
        
        unordered_set<string> edge_visited;
        
        string start(n, '0');
        string ret;

        aux(start, ret, edge_visited, k);
        reverse(begin(ret), end(ret));
        
        start.pop_back();
        return start + ret;
    }
    
    void aux(const string& start, string& ret, unordered_set<string>& edge_visited, int k) {
        char term = '0' + k;
        string node = start.substr(1);
        for (char ch = '0'; ch < term; ++ch) {
            node.push_back(ch);
            if (!edge_visited.count(node)) {
                edge_visited.insert(node);
                aux(node, ret, edge_visited, k);
                ret.push_back(ch);
            }
            node.pop_back();
        }
    }
};
