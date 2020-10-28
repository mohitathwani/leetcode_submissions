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
class Solution {
public:
    int recurse(ListNode* head, int n) {
        if (head == NULL) return 0;
        
        int c = recurse(head->next, n);
        
        if (c == n) {
            ListNode *deletionNode = head->next;
            //delete deletionNode;
            head->next = head->next->next;
        }
        
        return c + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = recurse(head, n);
        if (c == n && head != NULL) return head->next;
        return head;
    }
};