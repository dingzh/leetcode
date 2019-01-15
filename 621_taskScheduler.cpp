class Solution {
    struct Node {
        int task;
        int count;
        int valid_from;
        Node(int task, int count, int valid_from)
            :task(task), count(count), valid_from(valid_from) {}
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 256> task_cnt;
        task_cnt.fill(0);
        for (char task : tasks) ++task_cnt[task];
        
        priority_queue<pair<int,int>> pq;
        for (int task = 0; task < 256; ++task) if (task_cnt[task]){
            pq.emplace(task_cnt[task], task);
        }

        queue<Node> wait_q;
        int idx = 0;
        while (!wait_q.empty() || !pq.empty()) {
            if (!wait_q.empty()) {
                auto task = wait_q.front();
                if (task.valid_from <= idx) {
                    wait_q.pop();
                    pq.emplace(task.count, task.task);    
                }
            }
            
            if (!pq.empty()) {
                int count, task;
                tie(count, task) = pq.top(); pq.pop();
                if (count > 1) {
                    wait_q.emplace(task, count-1, idx + n + 1);
                }
                ++idx;
            } else if (!wait_q.empty()) {
                idx = wait_q.front().valid_from;
            }
            
        }
        
        return idx;
    }
};

