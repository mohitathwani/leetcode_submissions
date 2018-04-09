class Solution {
    func lengthOfLongestSubstring(_ s:String) -> Int {
    var maxLen = 0
    var i = 0
    
    var seenChracters = [Character:Int]()
    var charArray = Array(s)
    
    for j in 0..<s.count {
        if let seenCharIndex = seenChracters[charArray[j]] {
            i = max(i, seenCharIndex)
        }
        
        maxLen = max(maxLen, j - i + 1)
        seenChracters[charArray[j]] = j + 1
    }
    
    return maxLen
    
}

}