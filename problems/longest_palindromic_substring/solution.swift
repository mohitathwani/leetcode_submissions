class Solution {
    func longestPalindrome(_ s:String) -> String {
    var start = 0
    var end = 0

    let charArray = Array(s)
    
    for i in charArray.indices {
        let length = max(expandAround(i, j: i, charArray: charArray), expandAround(i, j: i + 1, charArray: charArray))
        if length > end - start {
            start = i - (length - 1) / 2
            end = i + (length / 2)
        }
    }
    
    let beginningIndex = s.index(s.startIndex, offsetBy: start)
    let endIndex = s.index(s.startIndex, offsetBy: end)
    return String(s[beginningIndex...endIndex])
}

func expandAround(_ i: Int, j: Int, charArray:[Character]) -> Int {
    var leftIndex = i
    var rightIndex = j
    
    while leftIndex >= 0 && rightIndex < charArray.count && charArray[leftIndex] == charArray[rightIndex] {
        leftIndex -= 1
        rightIndex += 1
    }
    
    return rightIndex - leftIndex - 1
}
}