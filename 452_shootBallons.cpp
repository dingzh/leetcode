class Solution {
    using Point = pair<int, int>;
    class PointComp {
    public:
        bool operator() (const Point& p1, const Point& p2) {
            return p1.second > p2.second; // dont care if the same
        }
    };

public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (!points.size()) return 0;
        priority_queue<Point, vector<Point>, PointComp>
            ballons(points.begin(), points.end());

        int ret = 1;
        int pos = ballons.top().second;
        
        while(!ballons.empty()) {
            if (ballons.top().first > pos) {
                pos = ballons.top().second;
                ++ret;
            }
            ballons.pop();
        }

        return ret;
    }
};
