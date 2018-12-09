/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* new_node = new Node(insertVal, nullptr);
        
        if (!head) {
            new_node->next = new_node;
            return new_node;
        }
        
        Node* p = head;
        while (p->next != head) {
            int currv = p->val, nextv = p->next->val;
            // cout << currv << '\t' << nextv << endl;
            if (currv == insertVal ||
                currv <= nextv && insertVal > currv && insertVal <= nextv ||
                currv > nextv && (insertVal > currv || insertVal <= nextv) ) 
            {
                new_node->next = p->next;
                p->next = new_node;
                return head;
            }
            p = p->next;
        }
        // cout << "out" << endl;
        
        p->next = new_node;
        new_node->next = head;
        return head;
    }
};
