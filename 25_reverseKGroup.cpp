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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        while (prev->next) {
            ListNode *tail = prev->next, *start = prev->next, *curr = start->next, *next;
            int cnt = k - 1;
            while (curr && cnt) {
                next = curr->next;
                curr->next = start;
                start = curr;
                curr = next;
                --cnt;
            }

            if (!cnt) {
                prev->next = start;
                tail->next = next;
                prev = tail;
            } else {
                ListNode *rhead = start, *rcurr = start->next;
                rhead->next = nullptr;
                while (rhead!= tail) {
                    auto tmp = rcurr->next;
                    rcurr->next = rhead;
                    rhead = rcurr;
                    rcurr = tmp;
                }
                break;
            }
        }

        return dummy.next;

    }
};
