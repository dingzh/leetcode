class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);

        int expect = 1;
        string token;
        while (getline(ss, token, ',') && expect) {
            if (token == "#") --expect;
            else ++expect;
        }
    
        // true when did not read anything and dont expect anything
        return ss.fail() && expect == 0;
    }
};
