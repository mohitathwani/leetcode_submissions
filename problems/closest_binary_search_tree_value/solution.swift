/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
func closestValue(_ root: TreeNode?, _ target: Double) -> Int {
  var root = root
  
  var result = root?.val ?? 0
  
  while root != nil {
    if Double(root!.val) == target {
      return root!.val
    }
    
    if abs(target - Double(result)) > abs(target - Double(root!.val)) {
      result = root!.val
    }
    
    if target < Double(root!.val) {
      root = root?.left
    } else {
      root = root?.right
    }
    
  }
  
  return result
}
}