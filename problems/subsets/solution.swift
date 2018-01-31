class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
            var nums = nums.sorted()
    var tempSubsets = [Int]()
    var result = [[Int]]()
    
    result += [tempSubsets]
    
    func compute(index: Int) {
        
        for i in index..<nums.count {
            tempSubsets += [nums[i]]
            result += [tempSubsets]
            
            compute(index: i + 1)
            tempSubsets.removeLast()
            
        }
    }
    
    compute(index: 0)
    
    return result
    }
}