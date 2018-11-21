class Solution {
    
public:
    bool validUtf8(vector<int>& data) {
        int expect = 0;
        
        for (int byte : data) {
            if (expect) {
                if ( (byte & 0xC0) != 0x80) return false;
                else --expect;
            } else {
                if      ( (byte & 0x80) == 0 ) expect = 0;      // 0xxxxx
                else if ( (byte & 0xE0) == 0xC0 ) expect = 1;  // 110xxx
                else if ( (byte & 0xF0) == 0xE0 ) expect = 2;
                else if ( (byte & 0xF8) == 0xF0 ) expect = 3;
                else return false;
            }
        }
        return expect == 0;
    }
};
