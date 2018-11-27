class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        
        int next = findNext(n);
        while (next != 1 && !visited.count(next)) {
            visited.insert(next);
            next = findNext(next);
        }
        
        return next == 1;
    }
    
    int findNext(int n) {
        string str = to_string(n);
        int ret = 0;
        for (char ch : str) {
            ret += pow((ch - '0'), 2);
        }
        return ret;
    }
};
