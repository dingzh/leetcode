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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy {0};
        ListNode* tail = &dummy;

        while (l1 && l2) {
            appendNode(l1->val <= l2->val ? l1 : l2, tail);
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    void appendNode(ListNode* &node, ListNode* &tail) {
        tail->next = node;
        tail = node;
        node = node->next;
    }
};
