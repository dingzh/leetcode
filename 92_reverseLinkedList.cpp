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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(0);
		dummy.next = head;

		ListNode* p = &dummy;
		for (int i = 1; i < m && p; ++i) {
			p = p->next;
		}
		// if (!p) throw xx;
		ListNode* sublist_prev = p;
		ListNode* sublist_head = p->next;
		ListNode* sublist_tail = sublist_head;
		
		int cnt = n - m;
		ListNode* ahead = sublist_head->next;
		
		while (cnt--) {
			ListNode* tmp = ahead->next;
			ahead->next = sublist_head;
			sublist_head = ahead;
			ahead = tmp;
		}
		sublist_tail->next = ahead;
		sublist_prev->next = sublist_head;

		return dummy.next;
	}
};
