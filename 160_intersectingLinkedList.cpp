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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        int lenA = 1, lenB = 1;
        auto pA = headA, pB = headB;

        while (pA->next) {++lenA; pA = pA->next;}
        while (pB->next) {++lenB; pB = pB->next;}

        if (pA != pB) return nullptr;

        if (lenA > lenB) {pA = headA; pB = headB;}
        else {pA = headB; pB = headA; auto tmp = lenA; lenA = lenB; lenB = tmp;}

        while (lenA > lenB) {
            pA = pA->next; --lenA;
        }

        while (pA != pB) {pA = pA->next; pB = pB->next;}

        return pA;
    }
};
