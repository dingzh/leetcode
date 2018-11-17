/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
    vector<pair<int,int>> direction {
        {1,0}, {0,1}, {-1,0},{0,-1}
    };
public:
    void cleanRoom(Robot& robot) {
        set<pair<int,int>> visited;
        dfs(robot, 0, 0, 0, visited);
    }
    
    void dfs(Robot& robot, int r, int c, int dir, set<pair<int,int>>& visited) {
        visited.emplace(r, c);
        robot.clean();
        
        for (int i = 0; i < 4; ++i) {
            int this_dir = (dir + i) % 4;
            int n_r = r + direction[this_dir].first;
            int n_c = c + direction[this_dir].second;
            if (!visited.count(make_pair(n_r, n_c)) && robot.move()) {
                dfs(robot, n_r, n_c, this_dir, visited);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
            } else {
                robot.turnLeft();
            }
        }
    }
};
