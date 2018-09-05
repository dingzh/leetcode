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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode *first = prev->next, *second = first->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
        }

        return dummy.next;
    }
};
