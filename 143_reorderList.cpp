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
    void reorderList(ListNode* head) {
        // if less than 2 nodes
        if (!head || !head->next) return;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* slow = &dummy, *fast = &dummy;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // split into two list
        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = nullptr;
        
        // reverse list2
        dummy.next = nullptr;
        while (list2) {
            ListNode* tmp = list2->next;
            list2->next = dummy.next;
            dummy.next = list2;
            list2 = tmp;
        }
        
        list2 = dummy.next;
        
        // merge list1 and list2, list2 might have one more element
        ListNode* p = &dummy;
        while (list1 && list2) {
            p->next = list1;
            list1 = list1->next;
            p = p->next;
            p->next = list2;
            list2 = list2->next;
            p = p->next;
        }
        
        p->next = list2;
    }
};
