/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class heapNode {
public:
    int val;
    ListNode *curr;
    ListNode *next;
    heapNode(ListNode *ln) {val = ln->val; curr = ln; next = ln->next;}
    bool operator<(const heapNode &hn) const{
        return val > hn.val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode *curr = &head;

        priority_queue<heapNode> q;
        for (auto list : lists) {
           if(list) q.emplace(list);
        }

        while (!q.empty()) {
            const auto top = q.top();
            q.pop();
            curr->next = top.curr;
            curr = top.curr;
            if(top.next) q.emplace(top.next);
        }

        return head.next;
    }
};
