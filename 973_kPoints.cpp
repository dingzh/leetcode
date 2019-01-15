class Solution {
    struct Point {
        int idx, dist;
        bool operator<(const Point& p) const {
            return dist < p.dist;
        }
        
        Point(int x, int y, int idx):idx(idx) { dist = x * x + y * y; }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size() <= K) return points;
        if (K == 0) return {};
        
        vector<Point> vec;
        for (int i = 0; i < points.size(); ++i) {
            vec.emplace_back(points[i][0], points[i][1], i);
        }
        
        nth_element(begin(vec), begin(vec) + K - 1, end(vec));
        
        vector<vector<int>> ret;
        for (int i = 0; i < K; ++i) {
            ret.push_back(move(points[vec[i].idx]));
        }
        
        return ret;
    }
};
