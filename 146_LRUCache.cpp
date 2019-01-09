class LRUCache {
    const int capacity;
    list<pair<int, int>> lru;
    using Objp = decltype(lru)::iterator;
    unordered_map<int, Objp> key_pos;
public:
    LRUCache(int capacity):capacity(capacity) {
        // assert(capacity);
    }

    int get(int key) {
        auto it = key_pos.find(key);
        if (it == end(key_pos))
            return - 1;

        auto list_it = it->second;
        lru.splice(begin(lru), lru, list_it);
        return lru.front().second;
    }

    void put(int key, int value) {
        auto it = key_pos.find(key);
        if (it != end(key_pos)) {
            auto list_it = it->second;
            list_it->second = value;
            lru.splice(begin(lru), lru, list_it);
        } else {
            if (key_pos.size() == capacity) {
                auto list_it = prev(end(lru));
                key_pos.erase(key_pos.find(list_it->first));
                lru.erase(list_it);
            }

            lru.emplace_front(key, value);
            key_pos[key] = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
