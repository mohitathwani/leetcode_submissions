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

extension TreeNode: Hashable, CustomStringConvertible {
  public var description: String {
    return "\(val)"
  }
  
  public var hashValue: Int {
    return val
  }
  
  public static func == (lhs: TreeNode, rhs: TreeNode) -> Bool {
    return lhs.val == rhs.val
  }
}

class Solution {
    func distanceK(_ root: TreeNode?, _ target: TreeNode?, _ K: Int) -> [Int] {
  guard let root = root, let target = target else {
    return [Int]()
  }
  
  var parentMap = [TreeNode:TreeNode?]()
  var result = [Int]()
  
  func dfs(currentNode: TreeNode?, parentNode: TreeNode?) {
    guard let currentNode = currentNode else {
      return
    }
    
    parentMap[currentNode] = parentNode
    dfs(currentNode: currentNode.left, parentNode: currentNode)
    dfs(currentNode: currentNode.right, parentNode: currentNode)
  }
  
  dfs(currentNode: root, parentNode: nil)
  
  func bfs(startNode: TreeNode) {
    var q = [TreeNode]()
    var seenSet = [TreeNode]()
    
    q.append(startNode)
    seenSet.append(startNode)
    
    var distanceMap = [TreeNode:Int]()
    distanceMap[startNode] = 0
    
      if K == 0 {
      result.append(startNode.val)
      return
    }
      
    while !q.isEmpty {
      let node = q.removeFirst()
      if let left = node.left, !seenSet.contains(left) {
        q.append(left)
        seenSet.append(left)
        
        distanceMap[left] = distanceMap[node]! + 1
        if distanceMap[left]! == K {
          result.append(left.val)
        }
      }
      
      if let right = node.right, !seenSet.contains(right) {
        q.append(right)
        seenSet.append(right)
        
        distanceMap[right] = distanceMap[node]! + 1
        if distanceMap[right]! == K {
          result.append(right.val)
        }
      }
      
      if let optionalParent = parentMap[node], let parent = optionalParent, !seenSet.contains(parent) {
        q.append(parent)
        seenSet.append(parent)
        
        distanceMap[parent] = distanceMap[node]! + 1
        if distanceMap[parent]! == K {
          result.append(parent.val)
        }
      }
    }
  }
  
  bfs(startNode: target)
  return result
}
}