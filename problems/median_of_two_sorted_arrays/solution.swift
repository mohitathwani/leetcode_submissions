class Solution {
    func findMedianSortedArrays(_ a: [Int], _ b: [Int]) -> Double {
        if a.count > b.count {
        return findMedianSortedArrays(b, a)
    }
    
    var start = 0
    var end = a.count
    
    while start <= end {
        var numElementsFromAInLeftPartition = (start + end) / 2
        var numElementsFromBInLeftPartition = ((a.count + b.count + 1) / 2) - numElementsFromAInLeftPartition
        
        var maxLeftA = (numElementsFromAInLeftPartition == 0) ? Int.min : a[numElementsFromAInLeftPartition - 1]
        var minRightA = (numElementsFromAInLeftPartition == a.count) ? Int.max : a[numElementsFromAInLeftPartition]
        
        
        var maxLeftB = (numElementsFromBInLeftPartition == 0) ? Int.min : b[numElementsFromBInLeftPartition - 1]
        var minRightB = (numElementsFromBInLeftPartition == b.count) ? Int.max : b[numElementsFromBInLeftPartition]
        
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if (a.count + b.count) % 2 == 0 {
                return Double(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0
            }
            
            return Double(max(maxLeftA, maxLeftB))
        }
        
        if maxLeftA > minRightB {
            end = numElementsFromAInLeftPartition - 1
        }
        
        if maxLeftB > minRightA{
            start = numElementsFromAInLeftPartition + 1
        }
    }
    
    return 0
    }
}