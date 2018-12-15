class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int size = A.size();
        // K >= 1, size >= 1
        // if (K == 0) return 0;
        // if (size == 0) return -1;
        
        int sum = 0;
        vector<int> prefix_sum;
        auto add = [&sum](int x) { sum += x; return sum;};
        transform(begin(A), end(A), back_inserter(prefix_sum), add);

        int ret = size + 1;
        deque<int> monoq;
        for (int i = 0; i < size; ++i) {
            if (prefix_sum[i] >= K)  ret = min(i + 1, ret);
            
            while (!monoq.empty() && prefix_sum[monoq.back()] >= prefix_sum[i]) {
                monoq.pop_back();
            }
            
            while (!monoq.empty() && prefix_sum[i] - prefix_sum[monoq.front()] >= K ) {
                ret = min(i- monoq.front(), ret);
                monoq.pop_front();
            }
            
            monoq.push_back(i);
        }

        return ret > size ? -1 : ret;
    }
};
