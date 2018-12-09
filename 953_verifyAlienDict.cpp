class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 256> order_map;
        for (int i = 0; i < order.length(); ++i) {
            order_map[order[i]] = i;
        }
        
        int size = words.size();
        for (int i = 1; i < size; ++i) {
            string& a = words[i-1];
            string& b = words[i];
            int idx = 0;
            int len = min(a.length(), b.length());
            while (idx < len && a[idx] == b[idx]) ++idx;
            if (idx < len && order_map[a[idx]] > order_map[b[idx]]
               || idx == len && a.length() > b.length()) return false;
        }
        return true;
    }
};
