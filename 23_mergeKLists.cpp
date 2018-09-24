/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class NodeCompare {
public:
    bool operator() (ListNode* lhs, ListNode* rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode* curr = &head;
        
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> 
            pq(lists.begin(), lists.end());

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            curr->next = top;
            curr = top;
            top = top->next;
            if (top) pq.push(top);
        }
        return head.next;
    }
};
