class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();

        int lt = matrix[0][0], rt = matrix[N-1][N-1];

        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;
            int count = countLessEqual(matrix, mid);
            if (count < k) {
                lt = mid + 1;
            } else {
                rt = mid;
            }
        }
        return lt;
    }

    int countLessEqual(const vector<vector<int>>& matrix, int val) {
        int ret = 0;
        for (const auto& row : matrix) {
            int cnt = distance(begin(row), upper_bound(begin(row), end(row), val));
            if (!cnt) return ret;
            ret += cnt;
        }
        return ret;
    }
};
