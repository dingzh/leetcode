class LRUCache {
    int slots;
    list<pair<int, int>> LRU_queue; // <key, value>
    using queue_pos = decltype(LRU_queue)::const_iterator;
    unordered_map<int, queue_pos> key_to_pos;
public:
    LRUCache(int capacity) {
        assert(capacity > 0);
        slots = capacity;
    }
    
    bool helper(int key) {
        // try to find key and move it to end of the list
        if (key_to_pos.find(key) == key_to_pos.end()) {
            return false;
        }
        
        auto& pos = key_to_pos[key];
        int val = (*pos).second;
        LRU_queue.erase(pos);
        LRU_queue.push_back(make_pair(key, val));
        pos = prev(LRU_queue.end());
        
        return true;
    }
    
    int get(int key) {
        if (!helper(key)) 
            return -1;
        return LRU_queue.back().second;
    }
    
    void put(int key, int value) {
        if (helper(key)) {
            LRU_queue.back().second = value;
            return ;
        }
        
        if (!slots) {
            int pkey = LRU_queue.front().first;
            key_to_pos.erase(pkey);
            LRU_queue.pop_front();
            ++slots;
        }

        --slots;
        LRU_queue.push_back(make_pair(key, value));
        key_to_pos[key] = prev(LRU_queue.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
