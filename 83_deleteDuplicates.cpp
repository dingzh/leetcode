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
        if (!head) return nullptr;

        ListNode *curr, *next, *tmp;
        curr = head;
        next = head->next;

        while (next) {
            if (curr->val != next->val) {
                curr->next = next;
                curr = next;
                next = next->next;
            } else {
                tmp = next;
                next = next->next;
                delete tmp;
            }
        }
        // make sure the list is null ended.
        curr->next = nullptr;

        return head;
    }
};
