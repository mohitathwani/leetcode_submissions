/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct comparator {  
bool operator()(const ListNode* l1, const ListNode* l2) {
    return l1->val > l2->val;
}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, std::vector<ListNode*>, comparator> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pq.push(lists[i]);
        }
        
        ListNode dummyHead;
        ListNode* temp = &dummyHead;
        
        while (!pq.empty()) {
            ListNode* top = pq.top();
            temp->next = new ListNode(top->val);
            temp = temp->next;
            
            pq.pop();
            if (top->next != NULL) pq.push(top->next);
        }
        
        return dummyHead.next;
    }
};