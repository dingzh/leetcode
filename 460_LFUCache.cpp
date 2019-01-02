class LFUCache {
    int min_freq = 0;
    const int capacity;
    unordered_map<int, list<int>> freq_to_keys;
    unordered_map<int, pair<int,int>> key_to_val_freq;
    unordered_map<int, list<int>::iterator> key_to_it;
public:
    LFUCache(int capacity):capacity(capacity) { }

    int get(int key) {
        auto it = key_to_val_freq.find(key);
        if (it == end(key_to_val_freq)) return -1;

        int value = it->second.first;
        int old_freq = it->second.second++;
        increaseFreq(key, old_freq);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return ;

        // if in cache, get will take care of frequence
        if (get(key) != -1) {
            key_to_val_freq[key].first = value;
            return ;
        }
        
        if (capacity == key_to_val_freq.size()) {
            auto& min_freq_keys = freq_to_keys[min_freq];
            int rkey = *prev(end(min_freq_keys));
            auto list_it = key_to_it[rkey];

            min_freq_keys.erase(list_it);
            key_to_val_freq.erase(key_to_val_freq.find(rkey));
            key_to_it.erase(key_to_it.find(rkey));
        }

        min_freq = 1;
        auto& key_list = freq_to_keys[1];
        key_list.emplace_front(key);
        key_to_it[key] = key_list.begin();
        key_to_val_freq[key] = make_pair(value, 1);
    }

    void increaseFreq(int key, int freq) {
        auto list_it = key_to_it[key];
        auto& old_freq_list = freq_to_keys[freq];
        auto& new_freq_list = freq_to_keys[freq + 1];

        new_freq_list.splice(begin(new_freq_list), old_freq_list, list_it);
        if (!old_freq_list.size()) {
            if (freq == min_freq) min_freq += 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
