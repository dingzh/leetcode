class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;  
        ListNode(): val(0), next(nullptr) {}
        ListNode(int val, ListNode* next): val(val), next(next) {}
    };
    
    int size = 0;
    ListNode dummyHead;
    ListNode* tail = &dummyHead;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* p = findIndex(index);
        return p ? p->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* p = new ListNode(val, nullptr);
        tail->next = p;
        tail = p;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* pos = findIndex(index - 1);
        if (!pos) return ;

        ListNode* p = new ListNode(val, pos->next);
        pos->next = p;
        ++size;

        if (tail == pos) tail = p;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* pos = findIndex(index - 1);
        if (!pos || !pos->next) return;
        
        auto tmp = pos->next;
        pos->next = tmp->next;
        if (tmp == tail) {
            tail = pos;
        }
        delete tmp;
        --size;
    }
    
    ListNode* findIndex(int index) {
        if (index == -1) return &dummyHead;
        if (index < 0 || index >= size) return nullptr;
        ListNode* ret = dummyHead->next;

        while (index--) ret = ret->next;
        return ret;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
