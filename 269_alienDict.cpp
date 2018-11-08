class Solution {
    typedef unordered_map<char, set<char>> Graph;
public:
    string alienOrder(vector<string>& words) {
        int size = words.size();
        if (size == 1) return words[0];
        if (size == 0) return "";
        Graph g;
        unordered_map<char, int> counts;
        unordered_set<char> no_info;
        

        for (int i = 1; i < size; ++i) {
            string& a = words[i-1], &b = words[i];
            int min_len = min( a.length(), b.length() );
            int j = 0;
            while (j < min_len) {
                if (a[j] != b[j]) {
                    if ( !g[a[j]].count( b[j] ) ) {
                        g[ a[j] ].insert( b[j] );
                        counts[ b[j] ] ++;
                    } 
                    break;
                } else {
                    no_info.insert(a[j]);
                }
                ++j;
            }
            
            while (j < min_len) {
                no_info.insert( a[j] );
                no_info.insert( b[j] );
                ++j;
            }
            
            for (int j = min_len; j < a.length(); ++j) {
                no_info.insert( a[j] );
            }
            for (int j = min_len; j < b.length(); ++j) {
                no_info.insert( b[j] );
            }
        }
        
        queue<char> q;
        for (auto& vert : g) {
            if ( counts.count( vert.first ) == 0 ) q.push(vert.first);
        }

        string ret;
        for (char ch : no_info) {
            if (!counts.count(ch) && !g.count(ch)) ret.push_back(ch);
        }
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            ret.push_back(ch);

            for (char nextch : g[ch]) {
                if (--counts[nextch] == 0) {
                    q.push( nextch );
                    counts.erase(nextch);
                }
            }
        }
        
        if (counts.size()) return "";
        else return ret;
    }
};
