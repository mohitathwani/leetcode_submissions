class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var nonZeroCount = 0
    
    for (index,value) in nums.enumerated() {
        if value != 0 {
            nums[nonZeroCount] = nums[index]
            nonZeroCount = nonZeroCount + 1
        }
    }
    
    while nonZeroCount < nums.count {
        nums[nonZeroCount] = 0
        nonZeroCount = nonZeroCount + 1
    }
    }
}