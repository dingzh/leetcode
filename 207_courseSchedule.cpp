class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int* preq_cnt = new int[numCourses];
        fill( preq_cnt, preq_cnt + numCourses, 0 );

        vector<vector<int> > depenency(numCourses, vector<int>());

        for (auto& item : prerequisites) {
            depenency[item.second].push_back(item.first);
            ++preq_cnt[item.first];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (preq_cnt[i] == 0) q.push(i);
        }

        int courseTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ++courseTaken;

            for (auto i : depenency[course]) {
                --preq_cnt[i];
                if (preq_cnt[i] == 0) q.push(i);
            }
        }

        return courseTaken == numCourses;
    }
};
