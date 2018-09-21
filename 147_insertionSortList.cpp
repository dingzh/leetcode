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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;


        ListNode dummy_head(0);
        dummy_head.next = head;

        ListNode* sorted = head;
        while (sorted->next) {
            if (sorted->val <= sorted->next->val) {
                sorted = sorted->next;
            } else {
                // remove p from the list
                ListNode* p = sorted->next;
                sorted->next = p->next;

                // insert back to appropriate position
                ListNode* pos = &dummy_head;
                while (pos->next->val < p->val) {
                    pos = pos->next;
                }

                p->next = pos->next;
                pos->next = p;
            }
        }

        return dummy_head.next;
    }
};
