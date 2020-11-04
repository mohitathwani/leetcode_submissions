/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        map<Node*, Node*> oldNewMap;
        Node *newHead = new Node(head->val);
        
        oldNewMap[head] = newHead;
        
        Node* tOld = head;
        Node* tNew = newHead;
        
        while (tOld != NULL) {
            //These duplicate if blocks should be abstracted out.
            if (tOld->next != NULL) {
                if (oldNewMap.count(tOld->next)) {
                    tNew->next = oldNewMap[tOld->next];
                } else {
                    tNew->next = new Node(tOld->next->val);
                    oldNewMap[tOld->next] = tNew->next;
                }
            }
            
            if (tOld->random != NULL) {
                if (oldNewMap.count(tOld->random)) {
                    tNew->random = oldNewMap[tOld->random];
                } else {
                    tNew->random = new Node(tOld->random->val);
                    oldNewMap[tOld->random] = tNew->random;
                }
            }
            
            tOld = tOld->next;
            tNew = tNew->next;
        }
        return newHead;
    }
};