// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char read_buf[4];
        int write_idx = 0;
        
        while (write_idx < n) {
            int readbytes = read4(read_buf);
            if (readbytes == 0) break;
            
            for (int i = 0; i < readbytes; ++i) {
                buf[write_idx++] = read_buf[i];
                if (write_idx == n) break ;
            }
        }
        return write_idx;
    }
};
