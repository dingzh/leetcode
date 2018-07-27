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
    ListNode* reverseList(ListNode* head) {
	if (!head) return nullptr;

	ListNode *newHead = head;
	ListNode *remain = head->next;
	head->next = nullptr;
	while(remain) {
		ListNode *prevHead = newHead;
		newHead = remain;
		remain = remain->next;
		newHead->next = prevHead;
	}

	return newHead;
    }
};

