class Solution {
    class SegmentTree {
        int n;
        vector<int> arr;
    public:
        SegmentTree(int size):arr(size * 2, 1), n(size) {
            for (int i = n - 1; i > 0; --i) {
                int left = i << 1;
                arr[i] = arr[left] + arr[left + 1];
            }
        }
        
        void update(int pos, int delta) {
            pos += n;
            while (pos) {
                arr[pos] += delta;
                pos >>= 1;
            }
        }
        
        int getSum(int l, int r) {
            l += n, r += n;
            int ret = 0;
            while (l <= r) {
                if (l & 1) { // l is right kid
                    ret += arr[l];
                    ++l;
                }
                if (!(r & 1)) { //
                    ret += arr[r];
                    --r;
                }
                l >>= 1;
                r >>= 1;
            }
            return ret;
        }
    };
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = people.size();
        if (!size) return {};
        
        SegmentTree st(size);
        
        vector<pair<int,int>> ret(size, {0,0});
        auto comp = [](const auto& p, const auto& rhs) {
            return p.first > rhs.first || p.first == rhs.first && p.second < rhs.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        for (auto& p : people) pq.push(p);
        
        int h, k;
        while (!pq.empty()) {
            tie(h, k) = pq.top();
            pq.pop();
            
            int pos = findPos(st, k+1, size);
            assert(pos != -1); // no solution
            st.update(pos, -1);
            ret[pos] = {h, k};
        }

        return ret;
    }
    
    int findPos(SegmentTree& st, int k, int size) { // find pos s.t. k empty positions
        int lt = k-1, rt = size - 1;
        while (lt < rt) {
            int mid = lt + (rt - lt) / 2;
            int seat = st.getSum(0, mid);
            if (seat < k) {
                lt = mid + 1;
            } else if (seat >= k) {
                rt = mid;
            }
        }
        return lt; 
    }
};
