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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* scout = &dummy, *p = &dummy;
        while (n-- && scout) {
            scout = scout->next;
        } // check scout to make sure n is valid
        
        while (scout->next) {
            p = p->next;
            scout = scout->next;
        }
        
        ListNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        
        return dummy.next;
    }
};
