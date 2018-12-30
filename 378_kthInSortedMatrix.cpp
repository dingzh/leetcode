class Solution {
    struct Element {
        int row;
        int col;
        int val;
        Element(int r, int c, int v):row(r), col(c), val(v) {}
        bool operator< (const Element& rhs) const {
            return val > rhs.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = row ? matrix.size() : 0;
        assert(col);
        
        priority_queue<Element> pq;
        for (int r = 0; r < row; ++r) {
            pq.emplace(r, 0, matrix[r][0]);
        }

        while (--k) {
            auto elem = pq.top();
            pq.pop();
            int r = elem.row, c = elem.col;
            if(c + 1 < col) 
                pq.emplace(r, c + 1, matrix[r][c+1]);
        }

        return pq.top().val;
    }
};
