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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int pivot = head->val;
        ListNode dummy_left(0);
        ListNode dummy_right(0);
        ListNode dummy_pivot(0);

        while (head) {
            ListNode* curr = head;
            head = head->next;

            if (curr->val < pivot) {
                curr->next = dummy_left.next;
                dummy_left.next = curr;
            } else if (curr ->val > pivot) {
                curr->next = dummy_right.next;
                dummy_right.next = curr;
            } else {
                curr->next = dummy_pivot.next;
                dummy_pivot.next = curr;
            }
        }

        // might be nullptr
        ListNode* ret_list = sortList(dummy_right.next);

        // ret_list might still be null now
        ListNode* pivot_tail = listTail(dummy_pivot.next); // will never be null
        pivot_tail->next = ret_list;
        ret_list = dummy_pivot.next;

        ListNode* sorted_left = sortList(dummy_left.next);
        if (!sorted_left) return ret_list;

        ListNode* left_tail = listTail(sorted_left);
        left_tail->next = ret_list;
        ret_list = sorted_left;
        return ret_list;
    }

    ListNode* listTail(ListNode* head) {
        ListNode* tail = head;
        while (tail->next) tail = tail->next;
        return tail;
    }
};
