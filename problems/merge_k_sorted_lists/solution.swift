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
func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
  guard lists.count > 0 else {
    return nil
  }
  
  guard lists.count >= 2 else {
    return lists.first!
  }
  
  var tempLists = lists
  
  while tempLists.count > 1 {
    guard let l1 = tempLists[0] else {
      tempLists.removeFirst()
      continue
    }
    
    tempLists.removeFirst()
    guard let l2 = tempLists[0] else {
      tempLists.removeFirst()
      tempLists.append(l1)
      continue
    }
    
    tempLists.removeFirst()
    tempLists.append(merge(l1: l1, l2: l2))
  }
  
  return tempLists.first!
}

func merge(l1: ListNode, l2: ListNode) -> ListNode? {
  var list1: ListNode? = l1
  var list2: ListNode? = l2
  
  if l1 === l2 {
    return l1
  }
  
  let result = ListNode(0)
  var tail: ListNode? = result
  
  while list1 != nil && list2 != nil {
    if (list1?.val)! <= (list2?.val)! {
      tail?.next = list1
      tail = tail?.next
      list1 = list1?.next
    } else {
      tail?.next = list2
      tail = tail?.next
      list2 = list2?.next
    }
  }
  
  if list1 == nil {
    while list2 != nil {
      tail?.next = list2
      tail = tail?.next
      list2 = list2?.next
    }
  }
  
  if list2 == nil {
    while list1 != nil {
      tail?.next = list1
      tail = tail?.next
      list1 = list1?.next
    }
  }
  
  return result.next
  
}
}