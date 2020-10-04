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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        ListNode* result = NULL;
        ListNode* temp = NULL;
        
        while(head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                if (result == NULL) {
                    result = head1;
                    temp = result;
                } else {
                    temp->next = head1;
                    temp = temp->next;
                }
                head1 = head1->next;
            } else {
                if (result == NULL) {
                    result = head2;
                    temp = result;
                } else {
                    temp->next = head2;
                    temp = temp->next;
                }
                head2 = head2->next;
            }
        }
        
        if(head1 != NULL) {
            temp->next = head1;
        }
        
        if(head2 != NULL) {
            temp->next = head2;
        }
        
        return result;
    }
};