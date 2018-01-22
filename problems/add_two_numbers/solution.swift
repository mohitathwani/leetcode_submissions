/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        
        if l2 == nil {
            return l1
        }
        
        var temp1 = l1
        var temp2 = l2
        
        var resultNode: ListNode!
        var tailNode = resultNode
        var sum = 0
        var carry = 0
        while (temp1 != nil && temp2 != nil) {
            sum = temp1!.val + temp2!.val + carry
            carry = sum / 10
            sum = sum % 10
            
            if resultNode == nil {
                resultNode = ListNode(sum)
                tailNode = resultNode
            } else {
                tailNode?.next = ListNode(sum)
                tailNode = tailNode?.next
            }
            
            temp1 = temp1!.next
            temp2 = temp2!.next
        }
        
        if temp1 != nil {
            while temp1 != nil {
                sum = temp1!.val + carry
                carry = sum / 10
                sum = sum % 10
                tailNode?.next = ListNode(sum)
                tailNode = tailNode?.next
                temp1 = temp1!.next
            }
        }
        
        if temp2 != nil {
            while temp2 != nil {
                
                sum = temp2!.val + carry
                carry = sum / 10
                sum = sum % 10
                tailNode?.next = ListNode(sum)
                tailNode = tailNode?.next
                temp2 = temp2!.next
            }
        }
        
        if carry == 1 {
            tailNode?.next = ListNode(carry)
            tailNode = tailNode?.next
        }
        return resultNode
    }
}