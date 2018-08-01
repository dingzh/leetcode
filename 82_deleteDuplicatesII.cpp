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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode *pre = &dummy, *curr = head, *diff;

        while (curr) {
            bool duplicate = false;
            diff = curr->next;
            while (diff && diff->val == curr->val) {
                diff = diff->next;
                duplicate = true;
            }
            if (duplicate) {
                pre->next = diff;
                while (curr != diff) { auto tmp = curr; curr = curr->next; delete tmp;}
            } else {
                pre = curr;
                curr = diff;
            }
        }

        return dummy.next;
    }
};
