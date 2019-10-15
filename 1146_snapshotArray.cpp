class SnapshotArray {
    int snap_id = 0;
    using entry = vector<pair<int, int>>;
    vector<entry> storage;
public:
    SnapshotArray(int length) {
        entry init(1, make_pair(0,0));
        storage = vector<entry>(length, init);
    }
    
    void set(int index, int val) {
        entry& history = storage[index];
        if (history.back().first != snap_id) {
            history.emplace_back(snap_id, val);
        } else {
            history.back().second = val;
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        entry& history = storage[index];

        int lt = 0, rt = history.size();
        while (lt + 1 < rt) {
            int mid = (lt + rt) / 2;
            if (history[mid].first <= snap_id) {
                lt = mid;
            } else {
                rt = mid;
            }
        }
        return history[lt].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
