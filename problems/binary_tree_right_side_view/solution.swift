/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func rightSideView(_ root: TreeNode?) -> [Int] {
        guard let r = root else {
            return [Int]()
        }
        
        var q = [(level: Int, node: TreeNode)]()
        q.append((1, r))
        
        var result = [Int]()
        
        while(!q.isEmpty) {
            let temp = q.removeFirst()
            if result.count < temp.level {
                result.append(temp.node.val)
            } else {
                result[temp.level - 1] = temp.node.val
            }
            
            if temp.node.left != nil {
                q.append((temp.level + 1, temp.node.left!))
            }
            
            if temp.node.right != nil {
                q.append((temp.level + 1, temp.node.right!))
            }
        }
        
        return result
    }
}