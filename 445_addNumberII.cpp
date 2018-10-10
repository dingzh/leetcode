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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;

        readList(stk1, l1);
        readList(stk2, l2);

        ListNode* res = nullptr;
        int size1 = stk1.size(), size2 = stk2.size();
        int size = max(size1, size2);
        int carry = 0;
        while (size--) {
            int sum = carry;
            if (!stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }

            if (!stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }

            carry = sum / 10;
            
            ListNode* tmp = new ListNode( sum % 10 );
            tmp->next = res;
            res = tmp;
        }

        if (carry) {
            ListNode* tmp = new ListNode( 1 );
            tmp->next = res;
            res = tmp;
        }

        return res;
    }

    void readList(stack<int>& stk, ListNode* num) {
        while (num) {
            stk.push(num->val);
            num = num->next;
        }
    }
};
