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
public:
    void cleanRoom(Robot& robot) {
        std::function<void()> go_back = [&] ()
        {
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        };
        
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        set<pair<int, int>> visited;
        
        std::function<void(int,int,int)>  backtrace = [&] (int r, int c, int di)
        {
            visited.insert({r, c});
            robot.clean();
            for (int d = 0; d < 4; d ++) {
                int ndi = (di + d) % 4;
                int dr = dirs[ndi][0];
                int dc = dirs[ndi][1];
                int nr = r + dr;
                int nc = c + dc;
                if (visited.find({nr,nc}) == visited.end() && robot.move() == true) {
                    backtrace(nr, nc, ndi);
                    go_back();
                }
                robot.turnRight();
            }
        };
        
        backtrace(0, 0, 0);
    }
};
