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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 0 or 1 element
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy, *fast = &dummy;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* list1 = head, *list2 = slow->next; // list2 might be 1 element longer
        slow->next = nullptr;
        
        // reverse list2
        dummy.next = nullptr;
        ListNode* p = &dummy;
        while (list2) {
            ListNode* next = list2->next;
            list2->next = dummy.next;
            dummy.next = list2;
            list2 = next;
        }
        list2 = dummy.next;
        
        // compare list1 and list2
        while (list1) { // list1 shorter or equal to list2
            if (list1->val != list2->val) return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
};
