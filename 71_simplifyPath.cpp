class Solution {
public:
    string simplifyPath(string path) {
        vector<string> path_stk;
        stringstream ss(path);

        string token;
        while ( getline(ss, token, '/') ) {
            if (token == "..") {
                if (!path_stk.empty()) { path_stk.pop_back(); }
            } else if (token != "." && !token.empty()) {
                path_stk.push_back( move(token) );
            }
        }

        string ret;
        for (auto& p : path_stk) {
            ret += "/";
            ret += p;
        }
        return ret.empty() ? "/" : ret;
    }
};
