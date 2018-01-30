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
    func isValidBST(_ root: TreeNode?, min: Int, max: Int) -> Bool {
    var validLeft = false
    var validRight = false
    
    if root == nil {
        return true
    }
    
    let nodeVal = root!.val
    if nodeVal > min && nodeVal < max {
        validLeft = isValidBST(root?.left, min: min, max: nodeVal)
        
        if validLeft == true {
            validRight = isValidBST(root?.right, min: nodeVal, max: max)
            
            return validRight && validLeft
        }
    }
    
    return false
}

func isValidBST(_ root: TreeNode?) -> Bool {
    return isValidBST(root, min: Int.min, max: Int.max)
}
}