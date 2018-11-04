// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char buffer[4];
    int pos = 4;
    int limit = 4;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int write_idx = 0;
        
        while (write_idx < n) {
            if (pos == limit) {
                pos = 0;
                limit = read4(buffer);
                if (limit == 0) break;
            }
            
            while (pos < limit) {
                buf[write_idx++] = buffer[pos++];
                if (write_idx == n) break;
            }
        }
        return write_idx;
    }
};
