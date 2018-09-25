/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return 0;

        int cnt = 0;
        ListNode* p = head;
        while (!p) {
            ++cnt;
            p = p->next;
        }

        return buildBBST(cnt, &head);
    }
    
    TreeNode* buildBBST(int size, ListNode** p_head) {
        if (!size) return nullptr;

        int lt_size = size >> 1;
        int rt_size = size - lt_size - 1;

        TreeNode* root = new TreeNode(0);
        if (lt_size) root->left = buildBBST(lt_size, p_head);

        root->val = (*p_head)->val;
        *p_head = (*p_head)->next;
        
        if (rt_size) root->right = buildBBST(rt_size, p_head);
        
        return root;
    }
    
    
};
