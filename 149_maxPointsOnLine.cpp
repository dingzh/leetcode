/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    struct HashPair {
        size_t operator() (const pair<int,int>& p) const {
            return static_cast<size_t>(31) * p.first + p.second;
        }
    };
public:
    int maxPoints(vector<Point>& points) {

        int size = points.size();
        if (size < 3) return size;
        
        int ret = 2;
        for (int i = 0; i < size; ++i) {
            
            unordered_map<pair<int,int>, int, HashPair> counts;
            
            int max_point = 0, overlap = 1; // overlap with self
            int x1 = points[i].x, y1 = points[i].y;
            
            for (int j = i + 1; j < size; ++j) {
                int x2 = points[j].x, y2 = points[j].y;
                int delt_x = x2 - x1, delt_y = y2 - y1;
                
                if (!delt_x && !delt_y) {
                    ++overlap;
                } else if (!delt_x) { // vertical line
                    
                    max_point = max(max_point, ++counts[{1, 0}]);
                } else {
                    int k = __gcd(delt_x, delt_y);
                    delt_x = delt_x / k;
                    delt_y = delt_y / k;
                    if (delt_x < 0) {
                        delt_x = -delt_x;
                        delt_y = -delt_y;
                    }
                    
                    max_point = max(max_point, ++counts[{delt_y, delt_x}]);
                }
            }
            ret = max(ret, overlap + max_point);
        }
        
        return ret;
    }
};
