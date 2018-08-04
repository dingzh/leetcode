/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pFast = head, *pSlow = head;

        while (pFast && pFast->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) break;
        }
        
        if (!pFast || !pFast->next) return nullptr;
        
        ListNode *p = head;
        while (p != pSlow) {p = p->next; pSlow = pSlow->next;}
        
        return p;
    }
};


