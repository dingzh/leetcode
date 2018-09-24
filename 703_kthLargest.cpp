class KthLargest {
    int kth;
    priority_queue<int, vector<int>, greater<int>>* pq;
public:
    KthLargest(int k, vector<int> nums):kth(k) {
        if (nums.size() < k) {
            pq = new priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
            return;
        }

        pq = new priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin() + k);
        for (auto it = nums.begin() + k; it != nums.end(); ++it) {
            if (*it <= pq->top()) continue;
            pq->pop();
            pq->push(*it);
        }
    }

    int add(int val) {
        if (pq->size() < kth) {
            pq->push(val);
        } else if (val > pq->top()) {
                pq->pop();
                pq->push(val);
        }

        return pq->top();
    }

    ~KthLargest() {
        delete pq;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
