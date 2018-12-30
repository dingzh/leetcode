/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    static int getSize(ListNode* root) {
        int ret = 0;
        while (root) {
            ++ret;
            root = root->next;
        }
        return ret;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = getSize(root);
        
        int base = size / k;
        int remd = size % k;
        
        vector<ListNode*> ret;
        for (int i = 0; i < remd; ++i) {
            ret.push_back(getLen(base + 1, root));
        }
        
        for (int i = remd; i < k; ++i) {
            ret.push_back(getLen(base, root));
        }
        return ret;
    }
    
    ListNode* getLen(int len, ListNode* & root) {
        if (!len) return nullptr;
        
        ListNode node(0);
        ListNode* prev = &node;
        
        while (len--) {
            prev->next = root;
            root = root->next;
            prev = prev->next;
        }
        
        prev->next = nullptr;
        return node.next;
    }
};
