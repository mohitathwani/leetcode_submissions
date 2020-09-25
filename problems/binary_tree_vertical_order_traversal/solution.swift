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
    var cache = [Int:[Int]]()
    
    func verticalOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else {return [[Int]]()}
        
        var q = [(col: Int, node: TreeNode)]()
        q.append((0, root))
        
        while !q.isEmpty {
            let first = q.removeFirst()
            
            if cache[first.col] == nil {
                cache[first.col] = [first.node.val]
            } else {
                cache[first.col]!.append(first.node.val)
            }
            
            if let left = first.node.left {
                q.append((first.col - 1, left))
            }
            
            if let right = first.node.right {
                q.append((first.col + 1, right))
            }
        }
        
        return cache.sorted {$0.key < $1.key}.map{$0.value}
    }
}