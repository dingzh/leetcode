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
    int numComponents(ListNode* head, vector<int>& G) {
        int ret = G.size();
        unordered_set<int> G_set( G.begin(), G.end() );

        bool prev_in_G = false;
        while (head) {
            bool this_in_G = G_set.count( head->val );
            if (this_in_G && prev_in_G) --ret;

            prev_in_G = this_in_G;
            head = head->next;
        }

        return ret;
    }
};
