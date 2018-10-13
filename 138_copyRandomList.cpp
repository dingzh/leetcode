/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> nodeStore;

        RandomListNode dummyHead(0);
        RandomListNode *p = &dummyHead;
        while (head) {
            RandomListNode* next, *nextRandom = nullptr;
            auto it = nodeStore.find(head);
            if (it == nodeStore.end()) {
                next = new RandomListNode(head->label);
                nodeStore.insert( {head, next} );
            } else {
                next = it->second;
            }
            if (head->random) {
                it = nodeStore.find(head->random);
                if (it == nodeStore.end()) {
                    nextRandom = new RandomListNode(head->random->label);
                    nodeStore.insert( {head->random, nextRandom} );
                } else {
                    nextRandom = it->second;
                }
                next->random = nextRandom;
            }

            p->next = next;
            p = next;
            head = head->next;
        }
        return dummyHead.next;
    }
};
