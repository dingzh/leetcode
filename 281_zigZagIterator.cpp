class ZigzagIterator {
    queue<pair<int, vector<int>*>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size()) q.emplace(0, &v1);
        if (v2.size()) q.emplace(0, &v2);
    }

    int next() {
        int idx;
        vector<int>* vec;
        tie(idx, vec) = q.front();
        q.pop();
        
        int ret = (*vec)[idx];
        ++idx;
        if (idx < vec->size()) q.emplace(idx, vec);
        
        return ret;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
