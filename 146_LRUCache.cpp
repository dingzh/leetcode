class LRUCache {
    struct cacheNode {
        int key;
        int val;
        cacheNode* prev;
        cacheNode* next;
        cacheNode(int _key = 0, int _val = 0):
            key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    void markUse(cacheNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        cacheNode* head = &dummyHead;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

    int maxsize;
    int currsize;
    cacheNode dummyHead;
    cacheNode dummyTail;
    unordered_map<int, cacheNode*> keyToNode;

public:
    // capacity must be larger than 0
    LRUCache(int capacity) {
        assert(capacity > 0);
        currsize = 0;
        maxsize = capacity;
public:
    LRUCache(int capacity):maxsize(capacity), currsize(0) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) {
            return -1;
        } else {
            cacheNode* node = it->second;
            markUse(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        cacheNode* node;

        auto it = keyToNode.find(key);
        if (it != keyToNode.end()) {
            node = it->second;
            node->val = value;
            markUse(node);
            return ;
        }

        if (currsize < maxsize) {
            node = new cacheNode(key, value);
            ++currsize;

            node->prev = &dummyHead;
            node->next = dummyHead.next;
            dummyHead.next = node;
            node->next->prev = node;

            keyToNode.insert({key, node});
        } else {
            node = dummyTail.prev;
            keyToNode.erase(node->key);

            node->key = key;
            node->val = value;
            markUse(node);
            keyToNode.insert({key, node});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
