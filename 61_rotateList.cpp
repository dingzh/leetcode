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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        k = k % len; // k is less than len
        if (!k) return head;
        
        tail->next = head;
        int step_to_head = len - k;
        ListNode* new_head = head;
        while (--step_to_head) {
            new_head = new_head->next;
        }
        ListNode* tmp = new_head;
        new_head = new_head->next;
        tmp->next = nullptr;
        return new_head;
    }
};
