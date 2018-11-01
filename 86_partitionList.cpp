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
    ListNode* partition(ListNode* head, int x) {
        int pivot = x;
        ListNode dummy_left(0);
        ListNode dummy_right(0);
        ListNode*  left_tail = &dummy_left;
        ListNode* right_tail = &dummy_right;

        while (head) {
            ListNode* curr = head;
            head = head->next;
            curr->next = nullptr;

            if (curr->val < pivot) {
                left_tail->next = curr;
                left_tail = curr;
            } else {
                right_tail->next = curr;
                right_tail = curr;
            }
        }
        
        left_tail->next = dummy_right.next;
        return dummy_left.next;
    }
};



