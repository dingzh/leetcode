class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        queue<int> visit_q;
        vector<int> marked(size, 0);

        int can_visit_cnt = 1;
        marked[0] = 1;
        visit_q.push(0);

        while (!visit_q.empty() && can_visit_cnt != size) {
            int front = visit_q.front();
            visit_q.pop();
            for (int key : rooms[front]) {
                if (marked[key]) continue;
                marked[key] = 1;
                visit_q.push(key);
                ++can_visit_cnt;
            }
        }

        return can_visit_cnt == size;
    }
};
