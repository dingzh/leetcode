// Forward declaration of ArrayReader class.
class ArrayReader;


class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int size = getSize(reader);
        
        int lt = 0, rt = size;
        
        while (lt < rt) {
            int mid = ( lt + rt ) >> 1;
            int val = reader.get(mid);
            
            if (val > target) {
                rt = mid;
            } else if (val < target) {
                lt = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    
    int getSize(const ArrayReader& reader) {
        constexpr int oob = 2147483647;
        
        int lt = 0, rt = 10000;
        while (lt < rt) {
            int mid = (lt + rt) >> 1;
            if (reader.get(mid) != oob) lt = mid + 1;
            else rt = mid;
        }

        return rt;
    }
};
