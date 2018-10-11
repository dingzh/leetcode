ass RandomizedSet {
    unordered_map<int, int> val_to_idx;
    vector<int> vals;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }
  
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( !val_to_idx.count(val) ) {
            val_to_idx[val] = vals.size();
            vals.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = val_to_idx.find(val);
        if (it != val_to_idx.end()) {
            int back = vals.back();
            int idx = it->second;
            
            vals[idx] = back;
            val_to_idx[back] = idx;
            
            vals.pop_back();
            val_to_idx.erase(it);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % vals.size();
        return vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
