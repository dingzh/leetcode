class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        
        --n;
        priority_queue<int, vector<int>, greater<int>> pq = {2,3,5};
        
        while (--n) {
            int top = pq.top();
            while (top == pq.top()) {
                pq.pop();
            }

            pq.push(top * 2);
            pq.push(top * 3);
            pq.push(top * 5);
        }

        return pq.top();
    }
};
