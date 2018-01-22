class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var seenNumbers = [Int:Int]()
        
        for (index, val) in nums.enumerated() {
            if seenNumbers[target - val] != nil {
                return [seenNumbers[target - val]!, index]
            }
            seenNumbers[val] = index
        }
        
        return [Int]()
    }
}